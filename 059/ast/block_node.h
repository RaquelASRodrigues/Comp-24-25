#pragma once

#include <cdk/ast/sequence_node.h>

namespace udf {

  /**
   * Class for describing block nodes.
   */
  class block_node: public cdk::basic_node {
    cdk::sequence_node *_declarations, *_stmts;

  public:
    block_node(int lineno, cdk::sequence_node *declarations, cdk::sequence_node *stmts) :
      cdk::basic_node(lineno), _declarations(declarations), _stmts(stmts) {
    }

  public:
    cdk::sequence_node* declarations() { return _declarations; }
    cdk::sequence_node* stmts() { return _stmts; }

    void accept(basic_ast_visitor *sp, int level) { sp->do_block_node(this, level); }

  };
} // udf