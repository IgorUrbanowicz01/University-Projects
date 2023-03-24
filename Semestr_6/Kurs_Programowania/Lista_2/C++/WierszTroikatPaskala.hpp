class WierszTrojkataPascala {
public:
    WierszTrojkataPascala(int n);
    int wspolczynnik(int m) const;
    ~WierszTrojkataPascala();

private:
    int n_;
    int* wiersz_;
};