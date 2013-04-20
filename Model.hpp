#ifndef MODEL_HPP
#define MODEL_HPP

class Model {
private:
    double i[3][3];
    double det;

    double a[3][3];
    double b[3];
    double r[3];

public:
    void setNear(double distance, double ticks);
    void setMiddle(double distance, double ticks);
    void setFar(double distance, double ticks);
    double getDistance(double ticks);
    void prepare();
    double calculate(double ticks);
};

#endif //MODEL_HPP