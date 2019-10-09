// Copyright (c) 2019 Sarun Rattanasiri
// under the 3-Clause BSD License
// https://opensource.org/licenses/BSD-3-Clause

#include "deferred_execution.h"

void deferred_execution__defer(DeferredExecution_Config* config,
                               DeferredExecution_State* state) {
  state->deferred = true;
}

void deferred_execution__execute(DeferredExecution_Config* config,
                                 DeferredExecution_State* state) {
  if (!state->deferred) {
    return;
  }
  state->deferred = false;
  if (config->target) {
    config->target();
  }
}
