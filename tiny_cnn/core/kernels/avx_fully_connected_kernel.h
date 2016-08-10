/*
    Copyright (c) 2016, Taiga Nomi, Edgar Riba
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#pragma once

#include "tiny_cnn/core/params/fully_params.h"
#include "tiny_cnn/core/kernels/tiny_fully_connected_kernel.h"

namespace tiny_cnn {
namespace core {
namespace kernels {

inline void avx_fully_connected_kernel(const fully_params& params,
                                       const tensor_t& in,
                                       const vec_t&    W,
                                       const vec_t&    b,
                                       tensor_t&       a,
                                       const bool      layer_parallelize) {
    tiny_fully_connected_kernel(params, in, W, b, a, layer_parallelize);
}

inline void avx_fully_connected_back_kernel(const fully_params& params,
                                            const tensor_t& prev_out,
                                            const vec_t&    W,
                                            tensor_t&       dW,
                                            tensor_t&       prev_delta,
                                            tensor_t&       curr_delta,
                                            tensor_t&       db,
                                            const bool      layer_parallelize) {
    tiny_fully_connected_back_kernel(params, prev_out, W, dW, prev_delta, curr_delta, db, layer_parallelize);
}

}  // namespace kernels
}  // namespace core
}  // namespace tiny_cnn