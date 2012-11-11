/*
 *   Copyright (c) 2012, Michael Lehn, Klaus Pototzky
 *
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *   1) Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *   2) Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in
 *      the documentation and/or other materials provided with the
 *      distribution.
 *   3) Neither the name of the FLENS development group nor the names of
 *      its contributors may be used to endorse or promote products derived
 *      from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef CXXLAPACK_INTERFACE_TBCON_TCC
#define CXXLAPACK_INTERFACE_TBCON_TCC 1

#include <iostream>
#include <cxxlapack/interface/interface.h>
#include <netlib/netlib.h>

namespace cxxlapack {

template <typename IndexType>
IndexType
tbcon(char                  norm,
      char                  uplo,
      char                  diag,
      IndexType             n,
      IndexType             kd,
      const float           *Ab,
      IndexType             ldAb,
      float                 &rCond,
      float                 *work,
      IndexType             *iWork)
{
    CXXLAPACK_DEBUG_OUT("stbcon");

    IndexType info;
    LAPACK_IMPL(stbcon)(&norm,
                        &uplo,
                        &diag,
                        &n,
                        &kd,
                        Ab,
                        ldAb,
                        &rCond,
                        work,
                        iWork,
                        &info);
#   ifndef NDEBUG
    if (info<0) {
        std::cerr << "info = " << info << std::endl;
    }
#   endif
    ASSERT(info>=0);
    return info;
}

template <typename IndexType>
IndexType
tbcon(char                  norm,
      char                  uplo,
      char                  diag,
      IndexType             n,
      IndexType             kd,
      const double          *Ab,
      IndexType             ldAb,
      double                &rCond,
      double                *work,
      IndexType             *iWork)
{
    CXXLAPACK_DEBUG_OUT("dtbcon");

    IndexType info;
    LAPACK_IMPL(dtbcon)(&norm,
                        &uplo,
                        &diag,
                        &n,
                        &kd,
                        Ab,
                        ldAb,
                        &rCond,
                        work,
                        iWork,
                        &info);
#   ifndef NDEBUG
    if (info<0) {
        std::cerr << "info = " << info << std::endl;
    }
#   endif
    ASSERT(info>=0);
    return info;
}


template <typename IndexType>
IndexType
tbcon(char                        norm,
      char                        uplo,
      char                        diag,
      IndexType                   n,
      IndexType                   kd,
      const std::complex<float >  *Ab,
      IndexType                   ldAb,
      float                       &rCond,
      std::complex<float >        *work,
      float                       *rWork)
{
    CXXLAPACK_DEBUG_OUT("ctbcon");

    IndexType info;
    LAPACK_IMPL(ctbcon)(&norm,
                        &uplo,
                        &diag,
                        &n,
                        &kd,
                        reinterpret_cast<const float  *>(Ab),
                        ldAb,
                        &rCond,
                        reinterpret_cast<float  *>(work),
                        rWork,
                        &info);
#   ifndef NDEBUG
    if (info<0) {
        std::cerr << "info = " << info << std::endl;
    }
#   endif
    ASSERT(info>=0);
    return info;
}

template <typename IndexType>
IndexType
tbcon(char                        norm,
      char                        uplo,
      char                        diag,
      IndexType                   n,
      IndexType                   kd,
      const std::complex<double>  *Ab,
      IndexType                   ldAb,
      double                      &rCond,
      std::complex<double>        *work,
      double                      *rWork)
{
    CXXLAPACK_DEBUG_OUT("ztbcon");

    IndexType info;
    LAPACK_IMPL(ztbcon)(&norm,
                        &uplo,
                        &diag,
                        &n,
                        &kd,
                        reinterpret_cast<const double *>(Ab),
                        ldAb,
                        &rCond,
                        reinterpret_cast<double *>(work),
                        rWork,
                        &info);
#   ifndef NDEBUG
    if (info<0) {
        std::cerr << "info = " << info << std::endl;
    }
#   endif
    ASSERT(info>=0);
    return info;
}

} // namespace cxxlapack

#endif // CXXLAPACK_INTERFACE_TBCON_TCC
