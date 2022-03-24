#include "Dimensions.h"
#include <iostream>
using namespace std;

Dims::Dims(float h, float w, float d) {
    this->h = h;
    this->w = w;
    this->d = d;
};

void Dims::fill() {
    printf("height = "); scanf("%f", &h);
    printf("width = "); scanf("%f", &w);
    printf("depth = "); scanf("%f", &d);
}

void Dims::display() {
    printf("(%.2f, %.2f, %.2f)\n", h, w, d);
}

Dims Dims::operator+(const Dims& dim) {
    Dims temp;
    temp.h = h + dim.h;
    temp.w = w + dim.w;
    temp.d = d + dim.d;
    return temp;
}

Dims Dims::operator-(const Dims& dim) {
    Dims temp;
    temp.h = h - dim.h;
    temp.w = w - dim.w;
    temp.d = d - dim.d;
    return temp;
}

Dims Dims::operator/(const Dims& dim) {
    Dims temp;
    temp.h = h / dim.h;
    temp.w = w / dim.w;
    temp.d = d / dim.d;
    return temp;
}

Dims Dims::operator*(const Dims& dim) {
    Dims temp;
    temp.h = h * dim.h;
    temp.w = w * dim.w;
    temp.d = d * dim.d;
    return temp;
}

Dims& Dims::operator+=(const Dims& dim) {
    h += dim.h;
    w += dim.w;
    d += dim.d;
    return *this;
}

Dims& Dims::operator-=(const Dims& dim) {
    h -= dim.h;
    w -= dim.w;
    d -= dim.d;
    return *this;
}

Dims& Dims::operator/=(const Dims& dim) {
    h /= dim.h;
    w /= dim.w;
    d /= dim.d;
    return *this;
}

Dims& Dims::operator*=(const Dims& dim) {
    h *= dim.h;
    w *= dim.w;
    d *= dim.d;
    return *this;
}

Dims Dims::operator+(const float val) {
    Dims temp;
    temp.h = h + val;
    temp.w = w + val;
    temp.d = d + val;
    return temp;
}

Dims Dims::operator-(const float val) {
    Dims temp;
    temp.h = h - val;
    temp.w = w - val;
    temp.d = d - val;
    return temp;
}

Dims Dims::operator/(const float val) {
    Dims temp;
    temp.h = h / val;
    temp.w = w / val;
    temp.d = d / val;
    return temp;
}

Dims Dims::operator*(const float val) {
    Dims temp;
    temp.h = h * val;
    temp.w = w * val;
    temp.d = d * val;
    return temp;
}

Dims& Dims::operator+=(const float val) {
    h += val;
    w += val;
    d += val;
    return *this;
}

Dims& Dims::operator-=(const float val) {
    h -= val;
    w -= val;
    d -= val;
    return *this;
}

Dims& Dims::operator/=(const float val) {
    h /= val;
    w /= val;
    d /= val;
    return *this;
}

Dims& Dims::operator*=(const float val) {
    h *= val;
    w *= val;
    d *= val;
    return *this;
}

Dims operator+(const float val, const Dims& d) {
    Dims temp;
    temp.h = d.h + val;
    temp.w = d.w + val;
    temp.d = d.d + val;
    return temp;
}
Dims operator-(const float val, const Dims& d) {
    Dims temp;
    temp.h = d.h - val;
    temp.w = d.w - val;
    temp.d = d.d - val;
    return temp;
}
Dims operator*(const float val, const Dims& d) {
    Dims temp;
    temp.h = d.h * val;
    temp.w = d.w * val;
    temp.d = d.d * val;
    return temp;
}
Dims operator/(const float val, const Dims& d) {
    Dims temp;
    temp.h = d.h / val;
    temp.w = d.w / val;
    temp.d = d.d / val;
    return temp;
}