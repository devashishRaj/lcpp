An algorithm is considered to be stateful if it retains some information across calls. 
An algorithm is considered deterministic, meaning that for a given input (the value provided for start), it will always produce the same output sequence.


### Pseudo-random number generators (PRNGs)

>A pseudo-random number generator (PRNG) is an algorithm that generates a sequence of numbers whose properties simulate a sequence of random numbers.

```cpp

    #include <iostream>

// For illustrative purposes only, don't use this
unsigned int LCG16() // our PRNG
{
    static unsigned int s_state{ 5323 };

    // Generate the next number

    // We modify the state using large constants and intentional overflow to make it hard
    // for someone to casually determine what the next number in the sequence will be.

    s_state = 8253729 * s_state + 2396403; // first we modify the state
    return s_state % 32768; // then we use the new state to generate the next number in the sequence
}

int main()
{
    // Print 100 random numbers
    for (int count{ 1 }; count <= 100; ++count)
    {
        std::cout << LCG16() << '\t';

        // If we've printed 10 numbers, start a new row
        if (count % 10 == 0)
            std::cout << '\n';
    }

    return 0;
}
```

- Seeding a PRNG
    - When a PRNG is instantiated, an initial value (or set of values) called a random seed (or seed for short) can be provided to initialize the state of the PRNG. When a PRNG has been initialized with a seed, we say it has been seeded.
    - the size of the seed value can be smaller than the size of the state of the PRNG. When this happens, we say the PRNG has been underseeded.
    (Ideally, every bit in the state is initialized from a seed of equal size, and every bit in the seed has been independently determined somehow. However, if a PRNG is underseeded, some number of bits in the state will need to be initialized from the same bits in the seed. If a PRNG is significantly underseeded (meaning the size of the seed is much smaller than the size of the state), the quality of the random results the PRNG produces can be impacted.)


#### What makes a good PRNG? 

1. The PRNG should generate each number with approximately the same probability.
    - This is called distribution uniformity , checked using a histogram.
2. The method by which the next number in the sequence is generated shouldn’t be predictable.

3. The PRNG should have a good dimensional distribution of numbers.
    -  the PRNG should generate low numbers, middle numbers, high numbers, even numbers, and odd numbers seemingly at random.
4. The PRNG should have a high period for all seeds
    -  The length of the sequence before a PRNG begins to repeat itself is known as the period.

5. The PRNG should be efficient

>As of C++20, the Mersenne Twister algorithm is the only PRNG that ships with C++ that has both decent performance and quality.

     