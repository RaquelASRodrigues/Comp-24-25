#pragma once

#include <cdk/ast/expression_node.h>
#include <cdk/ast/unary_operation_node.h>

namespace udf {

  /**
  * Class for describing the number of cells of tensor node.
  */
  class tensor_capacity_node : public cdk::unary_operation_node {

  public:
    tensor_capacity_node(int lineno, cdk::expression_node *tensor)
      : cdk::unary_operation_node(lineno, tensor) {}
    
    void accept(basic_ast_visitor *sp, int level) { sp->do_tensor_capacity_node(this, level);}
  };    
}//udf