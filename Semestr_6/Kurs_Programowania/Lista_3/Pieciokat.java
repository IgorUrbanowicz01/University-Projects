import java.lang.Math;

public class Pieciokat extends Figura{
    private int bok;


    Pieciokat(int a) {bok=a;}
    private float pole(){
        return (float)Math.pow(bok, 2)*Math.sqrt(25 + 10*Math.sqrt(5))/4;
    }
    private int obwód(){
        return  bok*5;
    }
}