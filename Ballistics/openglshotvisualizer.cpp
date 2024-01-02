#include "OpenGLShotVisualizer.h"

OpenGLShotVisualizer::OpenGLShotVisualizer(QWidget *parent)
    : QOpenGLWidget(parent), VBO(0), VAO(0), numberOfPoints(0) {
    vertexShaderSource = R"glsl(
        #version 330 core
        layout (location = 0) in vec3 position;
        void main() {
            gl_Position = vec4(position, 1.0);
        }
    )glsl";

    fragmentShaderSource = R"glsl(
        #version 330 core
        out vec4 FragColor;
        void main() {
            FragColor = vec4(1.0, 1.0, 1.0, 1.0); // White color
        }
    )glsl";

    QSurfaceFormat format;
    format.setVersion(3, 3); // Example: Request OpenGL version 3.3
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);


}

// ... rest of the functions as previously defined ...

OpenGLShotVisualizer::~OpenGLShotVisualizer() {
    makeCurrent();
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    doneCurrent();
}


void OpenGLShotVisualizer::setTrajectoryData(const QVector<TrajectoryPoint>& data) {
    QVector<QVector3D> points;
    for (const auto& point : data) {
        points.push_back(QVector3D(point.range, point.path, point.windage));
    }

    // Bind VBO and upload data
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, points.size() * sizeof(QVector3D), points.constData(), GL_STATIC_DRAW);

    numberOfPoints = points.size();

    update(); // Trigger a repaint
}


void OpenGLShotVisualizer::initializeGL() {
    initializeOpenGLFunctions();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // Check for shader compile errors
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        qDebug() << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog;
    }

    shaderProgram = new QOpenGLShaderProgram(this);
    shaderProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    shaderProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);

    if (!shaderProgram->link()) {
        qDebug() << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << shaderProgram->log();
    }


    // Set up VBO and VAO
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO); // Replace with the corresponding Qt function

    // Clear with black background
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}


void OpenGLShotVisualizer::resizeGL(int w, int h) {
    // Update viewport
    glViewport(0, 0, w, h);
}


void OpenGLShotVisualizer::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shaderProgram->bind();
    glBindVertexArray(VAO);

    // Set up the vertex attribute pointers
    glEnableVertexAttribArray(0); // Position attribute
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    // Draw the trajectory
    glDrawArrays(GL_LINE_STRIP, 0, numberOfPoints);

    glBindVertexArray(0);
    shaderProgram->release();
}



void OpenGLShotVisualizer::drawTrajectory() {
    // Bind your shader program
    shaderProgram->bind();

    // Bind the VAO (Vertex Array Object) and VBO (Vertex Buffer Object)
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Enable the vertex attribute array (assuming location 0 for position)
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    // Draw the line
    glDrawArrays(GL_LINE_STRIP, 0, numberOfPoints);

    // Unbind VAO and shader program
    glBindVertexArray(0);
    shaderProgram->release();
}

