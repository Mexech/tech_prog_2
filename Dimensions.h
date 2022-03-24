class Dims {
    public:
        explicit Dims(float h = 0, float w = 0, float d = 0);
        void fill();
        void display();
        Dims operator+(const Dims&); 
        Dims operator-(const Dims&); 
        Dims operator*(const Dims&); 
        Dims operator/(const Dims&); 
        Dims& operator+=(const Dims&); 
        Dims& operator-=(const Dims&); 
        Dims& operator/=(const Dims&); 
        Dims& operator*=(const Dims&);
        Dims operator+(const float); 
        Dims operator-(const float); 
        Dims operator*(const float); 
        Dims operator/(const float); 
        Dims& operator+=(const float); 
        Dims& operator-=(const float); 
        Dims& operator/=(const float); 
        Dims& operator*=(const float);
        friend Dims operator+(const float, const Dims&); 
        friend Dims operator-(const float, const Dims&); 
        friend Dims operator*(const float, const Dims&); 
        friend Dims operator/(const float, const Dims&);
    protected:
    private:
        float h, w, d;
};