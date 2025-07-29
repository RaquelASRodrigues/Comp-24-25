#pragma once

#include <cdk/ast/expression_node.h>

namespace udf {

  /**
  * Class for describing the dimension at a given index of a tensor node.
  */
  class tensor_dimension_node : public cdk::expression_node {
    cdk::expression_node *_tensor;
    cdk::expression_node *_index;

  public:
    tensor_dimension_node(int lineno, cdk::expression_node *tensor, cdk::expression_node *index)
      : cdk::expression_node(lineno), _tensor(tensor), _index(index) {}

    cdk::expression_node *tensor() { return _tensor; }
    
    cdk::expression_node *index() { return _index; } 

    void accept(basic_ast_visitor *sp, int level) { sp->do_tensor_dimension_node(this, level); }
  }; 
}//udf