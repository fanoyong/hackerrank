	
    public Difference (int[] elements) {
        this.elements = elements;
    }

    private int min = Integer.MAX_VALUE;
    private int max = Integer.MIN_VALUE;

    public void computeDifference() {
        for (int i = 0; i < elements.length; i++) {
            int e = elements[i];
            if (e > max) {
                max = e;
            }
            if (e < min) {
                min = e;
            }
        }
        maximumDifference = Math.abs(max-min);
    }
