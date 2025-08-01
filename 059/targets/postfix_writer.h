#pragma once

#include "targets/basic_ast_visitor.h"

#include <set>
#include <sstream>
#include <stack>
#include <cdk/emitters/basic_postfix_emitter.h>

namespace udf {

  //!
  //! Traverse syntax tree and generate the corresponding assembly code.
  //!
  class postfix_writer: public basic_ast_visitor {
    cdk::symbol_table<udf::symbol> &_symtab;
    std::set<std::string> _functions_to_declare;
    cdk::basic_postfix_emitter &_pf;
    int _lbl;

    bool _errors, _inFunctionBody, _inFunctionArgs; //, _inFunction, _inFunctionName;
    bool _inForInit;
    bool _returnSeen; // when building a function
    std::stack<int> _forIni, _forStep, _forEnd; // for break/repeat
    // std::stack<bool> _globals; // for deciding whether a variable is global or not
    std::shared_ptr<udf::symbol> _function; // for keeping track of the current function and its arguments
    int _offset; // current framepointer offset (0 means no vars defined)
    cdk::typename_type _lvalueType;

    // remember function name for resolving '@'
    std::string _currentFunctionName;
    std::string _currentBodyRetLabel; // where to jump when a return occurs of an exclusive section ends

  public:
    postfix_writer(std::shared_ptr<cdk::compiler> compiler, cdk::symbol_table<udf::symbol> &symtab,
                   cdk::basic_postfix_emitter &pf) :
        basic_ast_visitor(compiler), _symtab(symtab), _pf(pf), _lbl(0), _errors(false), _inFunctionBody(false), _inFunctionArgs(false),
         _inForInit(false), _returnSeen(false), _function(nullptr), _offset(0), _lvalueType(cdk::TYPE_VOID), _currentFunctionName(""), _currentBodyRetLabel("") {
    }

  public:
    ~postfix_writer() {
      os().flush();
    }

  private:
    /** Method used to generate sequential labels. */
    inline std::string mklbl(int lbl) {
      std::ostringstream oss;
      if (lbl < 0)
        oss << ".L" << -lbl;
      else
        oss << "_L" << lbl;
      return oss.str();
    }

    void error(int lineno, std::string s) {
      std::cerr << "error: " << lineno << ": " << s << std::endl;
    }

  public:
  // do not edit these lines
#define __IN_VISITOR_HEADER__
#include ".auto/visitor_decls.h"       // automatically generated
#undef __IN_VISITOR_HEADER__
  // do not edit these lines: end

  };

} // udf
