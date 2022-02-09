# google-test-systemc-tdd
SystemC integration with Google Test (gtest) to facilitate Test-Driven Development (TDD)

# Quick start

Open terminal on cloned folder
```bash
cmake -S . -B build
cmake --build build
./build/test_counter3
```

The expected result is a test run which shows 1 failed case (because the test case is incorrect).

# Rationale
SystemC is a very powerful tool in systems design, specially for microelectroncis, which allows developing and testing systems in a software environment (in contrast to HDL simulators). This means a huge chunk of modeling and experimentation can be done with easily downloadable tools and no need of paid software.

TDD in hardware models is difficult to achieve for two reasons
1. The process of elaborating a software model takes too long, so the TDD cycle is slow (>30s per test run)
2. Tests usually require step-by-step information passed through clock cycles, this is too low-level and requires boilerplate code

To simplify these steps, the following changes are proposed
1. Module classes have functions (methods) with simple input-output relationships represented
2. These functions don't have side effects
3. The module's step-by-step behavior can be described by the chaining of simple functions

This way, each function can be tested for specific behavior and functional erros can be pinpointed to a function or a small subset of functions.

This approach may lead to fragile tests, so it is advised to think about the hardware architecture before writing unit tests. This methodology is supposed to facilitate testing interfaces quicker than with traditional tools and design flows.

Google Test was the testing framework of choice because of its ease of integration and richness of features and 3rd party tools.

The project is only supposed to support TDD and does not substitute other means of testing modules.

# Dependencies and observations
- Google Test's version present in CMakeLists comes from its tutorial. Other versions can be experimented
- SystemC 2.3.3 used, [https://www.accellera.org/downloads/standards/systemc](compiled from source)
    - It should be compiled with the std=c++11 flag to be compatible with gtest!
    - Modify CMakeLists' SYSTEMC_PATH to your own SystemC Home path
    - Change line 25 "find_library (...)" from lib-linux64 to the equivalent of your system

# To-do list

Contributions to the tasks or the contents of the list are welcome
- Create module instance through fixture so it's available in all test cases
- Test in Windows environment
- Update gtest version if necessary
- Add more examples
- Think of how to minimize compilation time for larger examples
