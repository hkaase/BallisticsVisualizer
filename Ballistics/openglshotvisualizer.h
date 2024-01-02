#ifndef OPENGLSHOTVISUALIZER_H
#define OPENGLSHOTVISUALIZER_H
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>
#include <QVector>
#include <QVector3D>
#include "TrajectoryPoint.h"


class OpenGLShotVisualizer : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core {
    Q_OBJECT

public:
    explicit OpenGLShotVisualizer(QWidget *parent = nullptr);
    void setTrajectoryData(const QVector<TrajectoryPoint>& data);
    ~OpenGLShotVisualizer();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    QVector<TrajectoryPoint> trajectoryData;
    const char* vertexShaderSource;
    const char* fragmentShaderSource;
    QOpenGLShaderProgram* shaderProgram;
    GLuint VBO, VAO;
    int numberOfPoints;


    // Helper methods for rendering
    void drawTrajectory();
};
#endif // OPENGLSHOTVISUALIZER_H
