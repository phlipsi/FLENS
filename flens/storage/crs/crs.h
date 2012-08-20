
/*
 *   Copyright (c) 2007-2012, Michael Lehn
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

#ifndef FLENS_STORAGE_CRS_CRS_H
#define FLENS_STORAGE_CRS_CRS_H 1

#include <vector>

#include <flens/vectortypes/impl/densevector.h>
#include <flens/storage/array/array.h>
#include <flens/storage/coordstorage/coordstorage.h>
#include <flens/storage/indexoptions.h>

namespace flens {

template <typename T,
          typename I = IndexOptions<> >
class CRS
{
    public:
        typedef T                                   ElementType;
        typedef typename I::IndexType               IndexType;
        typedef CoordStorage<T, I, CoordRowColCmp>  CoordinateStorage;

        typedef DenseVector<Array<ElementType> >    ElementTypeVector;
        typedef DenseVector<Array<IndexType> >      IndexTypeVector;

        CRS();

        ~CRS();

        //-- operators ---------------------------------------------------------

        void
        operator=(const CoordinateStorage &coordinateStorage);

        //-- methods -----------------------------------------------------------

        const IndexType
        firstRow() const;

        const IndexType
        lastRow() const;

        const IndexType
        firstCol() const;

        const IndexType
        lastCol() const;

        const IndexType
        numRows() const;

        const IndexType
        numCols() const;

        const IndexType
        numNonZeros() const;

        const IndexTypeVector &
        rows() const;

        const IndexTypeVector &
        cols() const;

        const ElementTypeVector &
        values() const;

        void
        _compress(const CoordinateStorage &coordinateStorage);

    private:
        // Lehn:  I do not allow copying matrices with crs unless someone gives
        //        me a reason.
        CRS(const CRS &rhs);

        IndexType  _numRows, _numCols;
        IndexType  _firstRow, _firstCol;

        DenseVector<Array<IndexType> >  _rows;
        DenseVector<Array<IndexType> >  _cols;
        DenseVector<Array<T> >          _values;
};

} // namespace flens

#endif // FLENS_STORAGE_CRS_CRS_H
