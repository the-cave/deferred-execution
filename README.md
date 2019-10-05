# Deferred Execution for embedded devices

## What is it?

It is a tiny but essential glue code to orchestrate execution flows of a small embedded device.
Hard to describe concretely, but you will understand once you see [the source code](src/deferred_execution.c).

## What are some use cases of the library?

* Defer complex or long executions from an interrupt service routine
* Shallow stack frames by deferring function calls, and execute them in the main loop

## Compatabilities

The library will work anywhere as long as the C language works.
The author of the library uses it on STM8 devices, but it should run fine on AVR, PIC, MCS-51, etc.
If it is not, please open an issue on GitHub, you just found a bug.

## How to use this?

Just include the header to your project.
~~~c
#include "deferred_execution.h"
~~~
Declaring the function to be deferred.
~~~c
void async_function(void) {
  // do something asynchronously
}
~~~
Setup an instance
~~~c
const DeferredExecution_Config async_invoke_config = {
    // point to the function we declared earlier
    .target = &async_function
};
static DeferredExecution_State async_invoke_state;

// somewhere in main()
deferred_execution__init(&async_invoke_state);
~~~
Defer the execution in an interrupt service routine
~~~c
void some_isr() {
  deferred_execution__defer(
    &async_invoke_config,
    &async_invoke_state
  );
}
~~~
Execute it in the main loop
~~~c
for (;;) {
  deferred_execution__execute(
    &async_invoke_config,
    &async_invoke_state
  );
}
~~~

## License

Deferred Execution is released under the [BSD 3-Clause License](LICENSE.md). :tada:
