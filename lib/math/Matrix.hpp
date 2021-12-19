#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <vector>
#include <stdint.h>

namespace synmath {

    class SynMatrix {
    protected:
        /**
         * @brief The internal representation of the matrix.
         * It is a contigous, heap allocated array of \f$ M \times N \f$ double values.
         */
        double* _mat;
        /**
         * @brief The number of rows of the matrix.
         */
        uint32_t _m;
        /**
         * @brief The number of columns of the matrix.
         */
        uint32_t _n;
    public:
        /**
         * @brief Construct a new Matrix object.
         * 
         * @param m 
         * @param n 
         */
        SynMatrix(uint32_t m, uint32_t n);


    };
};

#endif // __MATRIX_H__