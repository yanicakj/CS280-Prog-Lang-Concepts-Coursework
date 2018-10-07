public class Complex {

    public Complex(int norm) {

        this(norm, 0);
    }

    public Complex(int norm, int imag) {

        this.norm = norm;
        this.imag = imag;
    }

    public Complex add(Complex second) {

        return new Complex(norm + second.norm, imag + second.imag);
    }

    public Complex add(int n) {

        return new Complex(norm + n, imag);
    }

    public Complex div(Complex second) {
        int den = ((second.norm*second.norm)+(second.imag*second.imag));
        return new Complex(((norm*second.norm) + (imag*second.imag))/den, ((imag*second.norm)-(norm*second.imag))/den);
    }

    public Complex div(int n) {

        return new Complex(norm / n, imag / n);
    }

    public Complex mul(Complex second) {

        return new Complex((norm * second.norm)-(imag * second.imag), (norm * second.imag)+(imag * second.norm));
    }

    public Complex mul(int n) {

        return new Complex(norm * n, imag * n);
    }

    public Complex sub(Complex second) {

        return new Complex(norm - second.norm, imag - second.imag);
    }

    public Complex sub(int n) {

        return new Complex(norm - n, imag);
    }

    public String toString() {

        return "(" + norm + " + " + imag + "i)";
    }

    private int norm;
    private int imag;
}
