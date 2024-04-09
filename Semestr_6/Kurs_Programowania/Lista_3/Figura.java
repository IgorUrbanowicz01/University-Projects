interface Geometria{
    public int obwód();
    public float pole();
}

abstract class Figura extends Geometria{
    @java.lang.Override
    public abstract int obwód() {}
    public abstract float pole();
}