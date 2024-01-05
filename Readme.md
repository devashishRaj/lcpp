## C++ snippets and notes .
> NOTE :may wanna use https://github.com/fabiospampinato/vscode-highlight or any regex based markdown highlighter for TODO , WARNING , BestPractice , NOTE and FIX etc .

Sample cli to produce a executable file "test" , you can use 'nasa' target in makefile
 which will compile with stricter flags
```zsh

clang++ -std=c++23 -Wall -g -glldb CH7/ch7_d.cpp -o bin/test

```

```text 
std::cerr is unbuffered, which means anything you send to it will output immediately.  
This helps ensure all debug output appears as soon as possible (at the cost of some performance,  
which we usually don’t care about when debugging).
```

- **Primary Goal: Make It Work**
  - The fundamental objective in programming is to ensure that the program functions
    correctly. The utility of a program is diminished if it doesn't work, regardless of
    its code quality.

- **Iterative Nature of Programming**
  - The saying emphasizes the iterative nature of programming: "You have to write a
    program once to know how you should have written it the first time." Implies that the
    initial solutions to problems are often not optimal.

- **Shortcut Approaches**
  - During the initial phase of making a program work, programmers often take shortcuts.
    Skip aspects like error handling, comments, and focus on quick problem-solving.

- **Learning as You Go**
  - The process involves learning from mistakes and discovering that initial ideas may
    not work as expected. Debugging code is sprinkled throughout to aid in issue
    diagnosis and error finding.

- **Post-Functionality Cleanup**
  - Once the program is functional, the job is not done, especially if the program is
    not a one-off. Cleanup involves removing temporary/debugging code, adding comments,
    handling error cases, and formatting code.

- **Optimizing for Maintainability**
  - New programmers often focus on performance optimization rather than prioritizing
    maintainability. Emphasis on the importance of making code readable,
    well-structured, and following best practices.

- **Continuous Refinement**
  - Solutions presented in tutorials may not be optimal initially; they evolve through
    continuous refinement. Perfection in programming is seen as an iterative process,
    requiring repeated passes and improvements.

- **Normalcy of Imperfection**
  - Encouragement not to be frustrated if initial solutions are not perfectly optimized.
    Acknowledges that achieving perfection in programming is a process of continuous
    improvement.


### Key insight

Spending a little time up front thinking about how to structure your program will lead to better code  
and less time spent finding and fixing errors.

I would say this is arguably the most important thing in programming and some of us,  
like me at first, took it for granted.
    —Reader Emeka Daniel, comment on learncpp.com

