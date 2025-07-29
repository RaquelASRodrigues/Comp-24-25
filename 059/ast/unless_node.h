#pragma once

#include <cdk/ast/basic_node.h>
#include <cdk/ast/sequence_node.h>

namespace udf {

  /**
   * Class for describing unless nodes.
   */
  class unless_node : public cdk::basic_node {
    cdk::expression_node *_condition;
    cdk::expression_node *_vector;
    std::string _function;
    cdk::expression_node *_count;

  public:
    unless_node(int lineno, cdk::expression_node *condition, cdk::expression_node *vector,
             const std::string &function, cdk::expression_node *count) :
        basic_node(lineno), _condition(condition), _vector(vector), _function(function), _count(count) {
    }

    cdk::expression_node *condition() { return _condition; }
    cdk::expression_node *vector()      { return _vector; }
    const std::string& function() const { return _function; }
    cdk::expression_node *count() { return _count; }

    void accept(basic_ast_visitor *sp, int level) { sp->do_unless_node(this, level); }

  };

} // udf