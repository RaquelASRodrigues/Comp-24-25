#pragma once

#include <cdk/ast/lvalue_node.h>
#include <cdk/ast/expression_node.h>
#include <cdk/ast/sequence_node.h>

namespace udf {

  /**
  * Class for describing the indexation of a position in a tensor node.
  */
  class tensor_index_node : public cdk::lvalue_node {
    cdk::expression_node *_tensor; 
    cdk::sequence_node *_index;

  public:
    tensor_index_node(int lineno, cdk::expression_node *tensor, cdk::sequence_node *index)
      : cdk::lvalue_node(lineno), _tensor(tensor), _index(index) {}
    
    cdk::expression_node *tensor() { return _tensor; } 

    cdk::sequence_node *index() { return _index; } 

    void accept(basic_ast_visitor *sp, int level) { sp->do_tensor_index_node(this, level);}
  }; 
}//udf