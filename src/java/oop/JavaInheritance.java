
    class Adder extends Arithmetic {

        @Override
        public int add(int a, int b) {
            return a + b;
        }

    }

    abstract class Arithmetic {
        public abstract int add(int a, int b);
    }
