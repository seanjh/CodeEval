/*Sieve of Eratosthenes

1) Create a list of consecutive integers from 2 through n: (2, 3, 4, ..., n).

2) Initially, let p equal 2, the first prime number.

3) Starting from p, enumerate its multiples by counting to n in increments of p,
and mark them in the list (these will be 2p, 3p, 4p, etc.; the p itself should
not be marked).

4) Find the first number greater than p in the list that is not marked. If there
was no such number, stop. Otherwise, let p now equal this new number (which is
the next prime), and repeat from step 3.*/

import java.util.LinkedList;

public class Eratosthenes {
	public static void main(String[] args) {
		LinkedList<Integer> primes = primeSieve(600000);
		
		for (int i = 0; i < primes.size(); i++) {
			System.out.print(primes.get(i) + " ");
			if (i + 1 % 20 == 0)
				System.out.println();
		}
	}

	public static LinkedList<Integer> primeSieve(int max) {
		int[] values = new int[max + 1];

		// Create a list of consecutive integers from 2 through n: (2, 3, 4, ..., n).
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