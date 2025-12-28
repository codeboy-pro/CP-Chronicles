/*
Problem Statement:
Mike has an unlimited number of unit resistors (each with resistance = 1).

Using these resistors, he can create new elements in two ways:
1. Series connection:
   - New resistance = current resistance + 1
2. Parallel connection:
   - New resistance = current resistance / (current resistance + 1)

Given a target resistance as a reduced fraction a / b,
the task is to find the minimum number of unit resistors
needed to build exactly this resistance.

It is guaranteed that a solution always exists.

---------------------------------------
Observation:
Instead of actually building resistor networks, we can
work directly with the fraction a / b.

At every step:
- If a > b, we reduce a using b.
- If b > a, we reduce b using a.

Each reduction corresponds to adding one unit resistor.

---------------------------------------
Important Insight:
When a > b:
- a can be reduced by subtracting b multiple times at once.
- This is equivalent to using (a / b) resistors.

Similarly, when b > a:
- b can be reduced using a.
- This uses (b / a) resistors.

This process continues until one value becomes zero.

---------------------------------------
Approach:
1. Read integers a and b.
2. Initialize a counter for resistors used.
3. While both a and b are non-zero:
   - If a > b:
       - Add a / b to the counter.
       - Set a = a % b.
   - Else:
       - Add b / a to the counter.
       - Set b = b % a.
4. Output the counter.

---------------------------------------
Time Complexity:
O(log(min(a, b)))

---------------------------------------
Space Complexity:
O(1)

---------------------------------------
Constraints:
1 ≤ a, b ≤ 10^18
---------------------------------------
*/

/*--- submission link
https://codeforces.com/contest/343/submission/355464586
*/

import java.util.*;

public class Solution2 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        long a = sc.nextLong();
        long b = sc.nextLong();

        long used = 0;

        // keep reducing until one value becomes zero
        while (a != 0 && b != 0) {
            if (a > b) {
                used += a / b;
                a = a % b;
            } else {
                used += b / a;
                b = b % a;
            }
        }

        System.out.println(used);
    }
}
