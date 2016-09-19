/*!
 *  Copyright (c) 2016 by Contributors
 * \file elemwise_unary_op.cc
 * \brief CPU Implementation of unary function.
 */
#include "./elemwise_unary_op.h"
#include "./elemwise_binary_op.h"

namespace mxnet {
namespace op {
// copy
MXNET_OPERATOR_REGISTER_UNARY(_copy)
.MXNET_DESCRIBE("Copy src to output")
.set_attr<FCompute>("FCompute<cpu>", UnaryCompute<cpu, mshadow_op::identity>)
.set_attr<nnvm::FGradient>("FGradient", ElemwiseGradUseNone{"_copy"});

// negative
MXNET_OPERATOR_REGISTER_UNARY(negative)
.MXNET_DESCRIBE("Negate src")
.set_attr<FCompute>("FCompute<cpu>", UnaryCompute<cpu, mshadow_op::negation>)
.set_attr<nnvm::FGradient>("FGradient", ElemwiseGradUseNone{"negative"});

// abs
MXNET_OPERATOR_REGISTER_UNARY(abs)
.MXNET_DESCRIBE("Take absolute value of the src")
.set_attr<FCompute>("FCompute<cpu>", UnaryCompute<cpu, mshadow_op::abs>)
.set_attr<nnvm::FGradient>("FGradient", ElemwiseGradUseIn{"_backward_abs"});

MXNET_OPERATOR_REGISTER_BINARY(_backward_abs)
.set_attr<FCompute>("FCompute<cpu>", BinaryCompute<cpu, unary_bwd<mshadow_op::sign> >);

// sign
MXNET_OPERATOR_REGISTER_UNARY(sign)
.MXNET_DESCRIBE("Take sign of the src")
.set_attr<FCompute>("FCompute<cpu>", UnaryCompute<cpu, mshadow_op::sign>)
.set_attr<nnvm::FGradient>("FGradient", ElemwiseGradUseIn{"_backward_sign"});

MXNET_OPERATOR_REGISTER_BINARY(_backward_sign)
.set_attr<FCompute>("FCompute<cpu>", BinaryCompute<cpu, unary_bwd<mshadow_op::sign_grad> >);

// round
MXNET_OPERATOR_REGISTER_UNARY(round)
.MXNET_DESCRIBE("Take round of the src")
.set_attr<FCompute>("FCompute<cpu>", UnaryCompute<cpu, mshadow_op::round>);

// ceil
MXNET_OPERATOR_REGISTER_UNARY(ceil)
.MXNET_DESCRIBE("Take ceil of the src")
.set_attr<FCompute>("FCompute<cpu>", UnaryCompute<cpu, mshadow_op::ceil>);

// floor
MXNET_OPERATOR_REGISTER_UNARY(floor)
.MXNET_DESCRIBE("Take floor of the src")
.set_attr<FCompute>("FCompute<cpu>", UnaryCompute<cpu, mshadow_op::floor>);

// square
MXNET_OPERATOR_REGISTER_UNARY(square)
.MXNET_DESCRIBE("Take square of the src")
.set_attr<FCompute>("FCompute<cpu>", UnaryCompute<cpu, mshadow_op::square>)
.set_attr<nnvm::FGradient>("FGradient", ElemwiseGradUseIn{"_backward_square"});

MXNET_OPERATOR_REGISTER_BINARY(_backward_square)
.set_attr<FCompute>("FCompute<cpu>", BinaryCompute<cpu, unary_bwd<mshadow_op::square_grad> >);

// sqrt
MXNET_OPERATOR_REGISTER_UNARY(sqrt)
.MXNET_DESCRIBE("Take square root of the src")
.set_attr<FCompute>("FCompute<cpu>", UnaryCompute<cpu, mshadow_op::square_root>)
.set_attr<nnvm::FGradient>("FGradient", ElemwiseGradUseOut{"_backward_sqrt"});

MXNET_OPERATOR_REGISTER_BINARY(_backward_sqrt)
.set_attr<FCompute>("FCompute<cpu>", BinaryCompute<cpu, unary_bwd<mshadow_op::square_root_grad> >);

// rsqrt
MXNET_OPERATOR_REGISTER_UNARY(rsqrt)
.MXNET_DESCRIBE("Take reciprocal square root of the src")
.set_attr<FCompute>("FCompute<cpu>", UnaryCompute<cpu, mshadow_op::reciprocal_square_root>)
.set_attr<nnvm::FGradient>("FGradient", ElemwiseGradUseIn{"_backward_rsqrt"});

MXNET_OPERATOR_REGISTER_BINARY(_backward_rsqrt)
.set_attr<FCompute>("FCompute<cpu>",
  BinaryCompute<cpu, unary_bwd<mshadow_op::reciprocal_square_root_grad> >);

// exp
MXNET_OPERATOR_REGISTER_UNARY(exp)
.MXNET_DESCRIBE("Take exp of the src")
.set_attr<FCompute>("FCompute<cpu>", UnaryCompute<cpu, mshadow_op::exp>)
.set_attr<nnvm::FGradient>("FGradient", ElemwiseGradUseOut{"_mul"});

// log
MXNET_OPERATOR_REGISTER_UNARY(log)
.MXNET_DESCRIBE("Take log of the src")
.set_attr<FCompute>("FCompute<cpu>", UnaryCompute<cpu, mshadow_op::log>)
.set_attr<nnvm::FGradient>("FGradient", ElemwiseGradUseIn{"_backward_log"});

MXNET_OPERATOR_REGISTER_BINARY(_backward_log)
.set_attr<FCompute>("FCompute<cpu>", BinaryCompute<cpu, unary_bwd<mshadow_op::log_grad> >);

// cos
MXNET_OPERATOR_REGISTER_UNARY(cos)
.MXNET_DESCRIBE("Take cos of the src")
.set_attr<FCompute>("FCompute<cpu>", UnaryCompute<cpu, mshadow_op::cos>)
.set_attr<nnvm::FGradient>("FGradient", ElemwiseGradUseIn{"_backward_cos"});

MXNET_OPERATOR_REGISTER_BINARY(_backward_cos)
.set_attr<FCompute>("FCompute<cpu>", BinaryCompute<cpu, unary_bwd<mshadow_op::cos_grad> >);

// sin
MXNET_OPERATOR_REGISTER_UNARY(sin)
.MXNET_DESCRIBE("Take sin of the src")
.set_attr<FCompute>("FCompute<cpu>", UnaryCompute<cpu, mshadow_op::sin>)
.set_attr<nnvm::FGradient>("FGradient", ElemwiseGradUseIn{"_backward_sin"});

MXNET_OPERATOR_REGISTER_BINARY(_backward_sin)
.set_attr<FCompute>("FCompute<cpu>", BinaryCompute<cpu, unary_bwd<mshadow_op::sin_grad> >);

// tan
MXNET_OPERATOR_REGISTER_UNARY(tan)
.MXNET_DESCRIBE("Take tan of the src")
.set_attr<FCompute>("FCompute<cpu>", UnaryCompute<cpu, mshadow_op::tan>)
.set_attr<nnvm::FGradient>("FGradient", ElemwiseGradUseOut{ "_backward_tan" });

MXNET_OPERATOR_REGISTER_BINARY(_backward_tan)
.set_attr<FCompute>("FCompute<cpu>", BinaryCompute<cpu, unary_bwd<mshadow_op::tan_grad> >);

// arcsin
MXNET_OPERATOR_REGISTER_UNARY(arcsin)
.MXNET_DESCRIBE("Take arcsin of the src")
.set_attr<FCompute>("FCompute<cpu>", UnaryCompute<cpu, mshadow_op::arcsin>)
.set_attr<nnvm::FGradient>("FGradient", ElemwiseGradUseIn{ "_backward_arcsin" });

MXNET_OPERATOR_REGISTER_BINARY(_backward_arcsin)
.set_attr<FCompute>("FCompute<cpu>", BinaryCompute<cpu, unary_bwd<mshadow_op::arcsin_grad> >);

// arccos
MXNET_OPERATOR_REGISTER_UNARY(arccos)
.MXNET_DESCRIBE("Take arccos of the src")
.set_attr<FCompute>("FCompute<cpu>", UnaryCompute<cpu, mshadow_op::arccos>)
.set_attr<nnvm::FGradient>("FGradient", ElemwiseGradUseIn{ "_backward_arccos" });

MXNET_OPERATOR_REGISTER_BINARY(_backward_arccos)
.set_attr<FCompute>("FCompute<cpu>", BinaryCompute<cpu, unary_bwd<mshadow_op::arccos_grad> >);

// arctan
MXNET_OPERATOR_REGISTER_UNARY(arctan)
.MXNET_DESCRIBE("Take arctan of the src")
.set_attr<FCompute>("FCompute<cpu>", UnaryCompute<cpu, mshadow_op::arctan>)
.set_attr<nnvm::FGradient>("FGradient", ElemwiseGradUseIn{ "_backward_arctan" });

MXNET_OPERATOR_REGISTER_BINARY(_backward_arctan)
.set_attr<FCompute>("FCompute<cpu>", BinaryCompute<cpu, unary_bwd<mshadow_op::arctan_grad> >);

}  // namespace op
}  // namespace mxnet