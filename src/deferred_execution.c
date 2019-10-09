// Copyright (c) 2019 Sarun Rattanasiri
// under the 3-Clause BSD License
// https://opensource.org/licenses/BSD-3-Clause

#include "deferred_execution.h"

void deferred_execution__defer(DeferredExecution_Config* config,
                               DeferredExecution_State* state) {
  state->deferred = 1;
}

void deferred_execution__execute(DeferredExecution_Config* config,
                                 DeferredExecution_State* state) {
  if (!state->deferred) {
    return;
  }
  state->deferred = 0;
  if (config->target) {
    config->target();
  }
}
