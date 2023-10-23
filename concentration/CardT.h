#ifndef CARDT
#define CARDT

template<typename T>
class CardT {
    public:

        CardT(){};
        CardT (T d) {
           data = d;
        }

        T Data(void) const;
        void Data(T);

        bool Faceup(void) const;
        void Faceup(bool);


    private:
        T data {};
        bool faceUp {false};

};

template <typename T>
T CardT<T>::Data() const{
    return data;
}

template <typename T>
void CardT<T>::Data(T value) {
    data = value;
}

template <typename T>
bool CardT<T>::Faceup() const{
    return faceUp;
}

template <typename T>
void CardT<T>::Faceup(bool x) {
    faceUp = x;
}

#endif