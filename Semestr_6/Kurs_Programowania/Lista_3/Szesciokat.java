import java.lang.Math;

public class Szesciokat extends Figura{
    private int bok;


    Szesciokat(int a) {bok=a;}
    private float pole(){
        return (float)Math.pow(bok, 2)*Math.sqrt(3)/2*3;
    }
    private int obwód(){
        return  bok*6;
    }
}