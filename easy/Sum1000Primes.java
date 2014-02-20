import java.util.LinkedList;

public class Sum1000Primes {
    public static void main(String[] args) {

        LinkedList<Integer> primes = primeSieve(8000);

        int sum = 0;
        for (int i = 0; i < 1000; i++) {
            sum += primes.get(i);
        }

        System.out.println(sum);
    }

    public static LinkedList<Integer> primeSieve(int max) {
        int[] values = new int[max + 1];

        // Create a list of consecutive integers from 2 through n: (0, 0, 2, 3, 4, ..., n).
        for (int i = 2; i <= max; i++) {
            values[i] = i;
        }

        int p = 2;

        while (p * 2 <= max) {
            for (int i = 2; (i * p) <= max; i++) {
                int index = p * i;

                if (values[index] != 0) {
                    values[index] = 0;
                }
            }

            p++;
            while (values[p] == 0) {
                p++;
            }
        }

        p = 2;
        LinkedList<Integer> primes = new LinkedList<>();
        
        for (int i = p; i < values.length; i++) {
            if (values[i] != 0)
                primes.add(new Integer(i));
        }

        return primes;
    }
}