#pragma once

#include <cdk/ast/expression_node.h>

namespace udf {

  /**
   * Class for describing if nodes.
   */
  class if_node : public cdk::basic_node {
    cdk::expression_node *_condition;
    cdk::basic_node *_block;

  public:
    if_node(int lineno, cdk::expression_node *condition, cdk::basic_node *block) :
        cdk::basic_node(lineno), _condition(condition), _block(block) {
    }

    cdk::expression_node *condition() { return _condition; }

    cdk::basic_node *block() { return _block; }

    void accept(basic_ast_visitor *sp, int level) { sp->do_if_node(this, level); }

  };

} // udf
