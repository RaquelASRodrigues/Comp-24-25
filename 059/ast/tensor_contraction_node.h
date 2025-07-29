#pragma once

#include <cdk/ast/expression_node.h>
#include <cdk/ast/binary_operation_node.h>

namespace udf {

  /**
  * Class for describing the contraction of two tensor nodes.
  */
  class tensor_contraction_node : public cdk::binary_operation_node {

  public:
    tensor_contraction_node(int lineno, cdk::expression_node *tensor_1, cdk::expression_node *tensor_2)
      : cdk::binary_operation_node(lineno, tensor_1, tensor_2) {}

    void accept(basic_ast_visitor *sp, int level) { sp->do_tensor_contraction_node(this, level); }
  }; 
}//udf