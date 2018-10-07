public class Main {

    public static void main(String args[]) {

        Complex a = new Complex(1, 2);
        Complex b = new Complex(1, 3);

        int i = 5;

        System.out.println(a + " + " + b + " = " + a.add(b));
        System.out.println(a + " - " + b + " = " + a.sub(b));
        System.out.println(a + " * " + b + " = " + a.mul(b));
        System.out.println(a + " / " + b + " = " + a.div(b));

        System.out.println(a + " + " + i + " = " + a.add(i));
        System.out.println(a + " - " + i + " = " + a.sub(i));
        System.out.println(a + " * " + i + " = " + a.mul(i));
        System.out.println(a + " / " + i + " = " + a.div(i));
        
    }

}
