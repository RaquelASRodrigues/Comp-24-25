#pragma once

#include <cdk/ast/expression_node.h>
#include <cdk/ast/unary_operation_node.h>

namespace udf {

  /**
  * Class for describing the dimensions of a tensor node.
  */
  class tensor_dimensions_node : public cdk::unary_operation_node {

  public:
    tensor_dimensions_node(int lineno, cdk::expression_node *tensor)
      : cdk::unary_operation_node(lineno, tensor) {}
    
    void accept(basic_ast_visitor *sp, int level) { sp->do_tensor_dimensions_node(this, level); }
  }; 
}//udf