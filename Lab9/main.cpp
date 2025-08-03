#include <iostream>
#include <string>

using namespace std;

class Device {
private:
    string brand;
    double powerConsumption;

public:
    void setBrand(const string &b) {
        brand = b;}
    string getBrand() const {
        return brand;}
    void setPowerConsumption(double pc) {
        powerConsumption = pc;}
    double getPowerConsumption() const {
        return powerConsumption;}
    virtual void displayInfo() const = 0; };

class Laptop : public Device {
    int batteryLife;
public:
    Laptop(int bl) : batteryLife(bl) {}
    void displayInfo() const override {
        cout << "Laptop Brand: " << getBrand() << endl;
        cout << "Power Consumption: " << getPowerConsumption() << "W" << endl;
        cout << "Battery Life: " << batteryLife << " hours" << endl;
    }};
class Smartphone : public Device {
    string os;
public:
    Smartphone(const string &os) : os(os) {}
    void displayInfo() const override {
        cout << "Smartphone Brand: " << getBrand() << endl;
        cout << "Power Consumption: " << getPowerConsumption() << "W" << endl;
        cout << "Operating System: " << os << endl;
    }  };

int main() {
    Laptop laptop(8);
    laptop.setBrand("Dell");
    laptop.setPowerConsumption(65);
    Smartphone smartphone("Android");
    smartphone.setBrand("Samsung");
    smartphone.setPowerConsumption(15);
    Device *devices[2];
    devices[0] = &laptop;
    devices[1] = &smartphone;
    for (int i = 0; i < 2; ++i) {
        devices[i]->displayInfo();
        cout << endl;}
    return 0;
}

