// Copyright (c) 2019 Sarun Rattanasiri
// under the 3-Clause BSD License
// https://opensource.org/licenses/BSD-3-Clause

#ifndef __DEFERRED_EXECUTION_H
#define __DEFERRED_EXECUTION_H

#include <stdbool.h>

typedef struct _deferred_execution__config {
  void (*target)(void);
} DeferredExecution_Config;

typedef struct _deferred_execution__state {
  bool deferred;
} DeferredExecution_State;

#define deferred_execution__init(state) \
  do {                                  \
    (state)->deferred = 0;              \
  } while (0)

void deferred_execution__defer(DeferredExecution_Config* config,
                               DeferredExecution_State* state);

void deferred_execution__execute(DeferredExecution_Config* config,
                                 DeferredExecution_State* state);

#endif
