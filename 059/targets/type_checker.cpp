#include <string>
#include "targets/type_checker.h"
#include ".auto/all_nodes.h"  // automatically generated
#include <cdk/types/primitive_type.h>

#include "udf_parser.tab.h"

#define ASSERT_UNSPEC { if (node->type() != nullptr && !node->is_typed(cdk::TYPE_UNSPEC)) return; }

//---------------------------------------------------------------------------

void udf::type_checker::do_sequence_node(cdk::sequence_node *const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++)
    node->node(i)->accept(this, lvl);
}

void udf::type_checker::do_block_node(udf::block_node * const node, int lvl) {
  // EMPTY
}

//---------------------------------------------------------------------------

void udf::type_checker::do_nil_node(cdk::nil_node *const node, int lvl) {
  // EMPTY
}
void udf::type_checker::do_data_node(cdk::data_node *const node, int lvl) {
  // EMPTY
}

void udf::type_checker::do_not_node(cdk::not_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  if (node->argument()->is_typed(cdk::TYPE_INT)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else if (node->argument()->is_typed(cdk::TYPE_UNSPEC)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->argument()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else {
    throw std::string("wrong type in unary logical expression");
  }
}

void udf::type_checker::do_and_node(cdk::and_node *const node, int lvl) {
  do_BooleanLogicalExpression(node, lvl);
}
void udf::type_checker::do_or_node(cdk::or_node *const node, int lvl) {
  do_BooleanLogicalExpression(node, lvl);
}

//---------------------------------------------------------------------------

void udf::type_checker::do_integer_node(cdk::integer_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void udf::type_checker::do_double_node(cdk::double_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
}

void udf::type_checker::do_string_node(cdk::string_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
}

//---------------------------------------------------------------------------

void udf::type_checker::do_address_of_node(udf::address_of_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->lvalue()->accept(this, lvl + 2);
  node->type(cdk::reference_type::create(4, node->lvalue()->type()));
}

void udf::type_checker::do_stack_alloc_node(udf::stack_alloc_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  if (!node->argument()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in allocation expression");
  }
  // TODO other types
  node->type(cdk::reference_type::create(4, cdk::primitive_type::create(8, cdk::TYPE_DOUBLE)));
}

void udf::type_checker::do_nullptr_node(udf::nullptr_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::reference_type::create(4, nullptr));
}

//---------------------------------------------------------------------------

void udf::type_checker::processUnaryExpression(cdk::unary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  if (node->argument()->is_typed(cdk::TYPE_INT) || node->argument()->is_typed(cdk::TYPE_DOUBLE)
                                                || node->argument()->is_typed(cdk::TYPE_TENSOR)) {
    node->type(node->argument()->type());
  } else {
    throw std::string("wrong type in argument of unary expression");
  }
}

void udf::type_checker::do_unary_minus_node(cdk::unary_minus_node *const node, int lvl) {
  processUnaryExpression(node, lvl);
}

void udf::type_checker::do_unary_plus_node(cdk::unary_plus_node *const node, int lvl) {
  processUnaryExpression(node, lvl);
}

//---------------------------------------------------------------------------
//protected:
void udf::type_checker::do_IntOnlyExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (!node->left()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary operator (left)");
  }

  node->right()->accept(this, lvl + 2);
  if (!node->right()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary operator (right)");
  }

  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

//---------------------------------------------------------------------------
//protected:
void udf::type_checker::do_IDTExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);

  if (node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_DOUBLE)) {
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  } else if (node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_INT)) {
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  } else if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_DOUBLE)) {
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  } else if (node->left()->is_typed(cdk::TYPE_TENSOR) && node->right()->is_typed(cdk::TYPE_TENSOR)) {
    if (cdk::tensor_type::cast(node->left()->type())->dims() == cdk::tensor_type::cast(node->left()->type())->dims()) {
      node->type(node->left()->type());
    } else {
      throw std::string("tensor types don't match in binary expression");
    }
  } else if (node->left()->is_typed(cdk::TYPE_TENSOR) && (node->right()->is_typed(cdk::TYPE_INT)
                                                     || node->right()->is_typed(cdk::TYPE_DOUBLE))) {
    node->type(node->left()->type());
  } else if ((node->left()->is_typed(cdk::TYPE_INT)
           || node->left()->is_typed(cdk::TYPE_DOUBLE)) && node->right()->is_typed(cdk::TYPE_TENSOR)) {
    node->type(node->right()->type());
  } else if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_INT)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else if (node->left()->is_typed(cdk::TYPE_UNSPEC) && node->right()->is_typed(cdk::TYPE_UNSPEC)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->left()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->right()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else {
    throw std::string("wrong types in binary expression");
  }
}

//---------------------------------------------------------------------------
//protected:
void udf::type_checker::do_PIDTExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);

  if (node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_DOUBLE)) {
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  } else if (node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_INT)) {
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  } else if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_DOUBLE)) {
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  } else if (node->left()->is_typed(cdk::TYPE_POINTER) && node->right()->is_typed(cdk::TYPE_INT)) {
    node->type(node->left()->type());
  } else if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_POINTER)) {
    node->type(node->right()->type());
  } else if (node->left()->is_typed(cdk::TYPE_TENSOR) && node->right()->is_typed(cdk::TYPE_TENSOR)) {
    if (cdk::tensor_type::cast(node->left()->type())->dims() == cdk::tensor_type::cast(node->left()->type())->dims()) {
      node->type(node->left()->type());
    } else {
      throw std::string("tensor types don't match in binary expression");
    }
  } else if (node->left()->is_typed(cdk::TYPE_TENSOR) && (node->right()->is_typed(cdk::TYPE_INT)
                                                     || node->right()->is_typed(cdk::TYPE_DOUBLE))) {
    node->type(node->left()->type());
  } else if ((node->left()->is_typed(cdk::TYPE_INT)
           || node->left()->is_typed(cdk::TYPE_DOUBLE)) && node->right()->is_typed(cdk::TYPE_TENSOR)) {
    node->type(node->right()->type());
  } else if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_INT)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else if (node->left()->is_typed(cdk::TYPE_UNSPEC) && node->right()->is_typed(cdk::TYPE_UNSPEC)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->left()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->right()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else {
    throw std::string("wrong types in binary expression");
  }
}

//---------------------------------------------------------------------------
//protected:
void udf::type_checker::do_ScalarLogicalExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (!(node->left()->is_typed(cdk::TYPE_INT) || node->left()->is_typed(cdk::TYPE_DOUBLE))) {
    throw std::string("wrong type in binary logical expression (left)");
  }

  node->right()->accept(this, lvl + 2);
  if (!(node->right()->is_typed(cdk::TYPE_INT) || node->right()->is_typed(cdk::TYPE_DOUBLE))) {
    throw std::string("wrong type in binary logical expression (right)");
  }

  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

//protected:
void udf::type_checker::do_BooleanLogicalExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (!node->left()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary expression");
  }

  node->right()->accept(this, lvl + 2);
  if (!node->right()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary expression");
  }

  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

//protected:
void udf::type_checker::do_GeneralLogicalExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  if (node->left()->is_typed(cdk::TYPE_POINTER) && !node->right()->is_typed(cdk::TYPE_POINTER)) {
    throw std::string("wrong types in binary expression");
  } else if (node->left()->is_typed(cdk::TYPE_POINTER)) {
    //TODO: check pointer types
  } else if ((node->left()->is_typed(cdk::TYPE_TENSOR) && !node->right()->is_typed(cdk::TYPE_TENSOR)) ||
            (!node->left()->is_typed(cdk::TYPE_TENSOR) && node->right()->is_typed(cdk::TYPE_TENSOR))) {
    throw std::string("wrong types in binary expression");
  } else if (node->left()->is_typed(cdk::TYPE_TENSOR) && node->right()->is_typed(cdk::TYPE_TENSOR)) {
    if (cdk::tensor_type::cast(node->left()->type())->dims() != cdk::tensor_type::cast(node->right()->type())->dims()) {
      throw std::string("tensor types don't match in binary logical expression");
    }
  }

  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

//---------------------------------------------------------------------------

void udf::type_checker::do_add_node(cdk::add_node *const node, int lvl) {
  do_PIDTExpression(node, lvl);
}
void udf::type_checker::do_sub_node(cdk::sub_node *const node, int lvl) {
  do_PIDTExpression(node, lvl);
}
void udf::type_checker::do_mul_node(cdk::mul_node *const node, int lvl) {
  do_IDTExpression(node, lvl);
}
void udf::type_checker::do_div_node(cdk::div_node *const node, int lvl) {
  do_IDTExpression(node, lvl);
}
void udf::type_checker::do_mod_node(cdk::mod_node *const node, int lvl) {
  do_IntOnlyExpression(node, lvl);
}
void udf::type_checker::do_lt_node(cdk::lt_node *const node, int lvl) {
  do_ScalarLogicalExpression(node, lvl);
}
void udf::type_checker::do_le_node(cdk::le_node *const node, int lvl) {
  do_ScalarLogicalExpression(node, lvl);
}
void udf::type_checker::do_ge_node(cdk::ge_node *const node, int lvl) {
  do_ScalarLogicalExpression(node, lvl);
}
void udf::type_checker::do_gt_node(cdk::gt_node *const node, int lvl) {
  do_ScalarLogicalExpression(node, lvl);
}
void udf::type_checker::do_ne_node(cdk::ne_node *const node, int lvl) {
  do_GeneralLogicalExpression(node, lvl);
}
void udf::type_checker::do_eq_node(cdk::eq_node *const node, int lvl) {
  do_GeneralLogicalExpression(node, lvl);
}

//---------------------------------------------------------------------------

void udf::type_checker::do_sizeof_node(udf::sizeof_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->expression()->accept(this, lvl + 2);
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

//---------------------------------------------------------------------------

void udf::type_checker::do_variable_node(cdk::variable_node *const node, int lvl) {
  ASSERT_UNSPEC;
  const std::string &id = node->name();
  std::shared_ptr<udf::symbol> symbol = _symtab.find(id);

  if (symbol != nullptr) {
    node->type(symbol->type());
  } else {
    throw id;
  }
}

void udf::type_checker::do_index_node(udf::index_node * const node, int lvl) {
  ASSERT_UNSPEC;
  std::shared_ptr<cdk::reference_type> btype;

  if (node->base()) {
    node->base()->accept(this, lvl + 2);
    btype = cdk::reference_type::cast(node->base()->type());
    if (!node->base()->is_typed(cdk::TYPE_POINTER)) throw std::string("pointer expression expected in index left-value");
  } else {
    btype = cdk::reference_type::cast(_function->type());
    if (!_function->is_typed(cdk::TYPE_POINTER)) throw std::string("return pointer expression expected in index left-value");
  }

  node->index()->accept(this, lvl + 2);
  if (!node->index()->is_typed(cdk::TYPE_INT)) throw std::string("integer expression expected in left-value index");

  node->type(btype->referenced());
}

void udf::type_checker::do_rvalue_node(cdk::rvalue_node *const node, int lvl) {
  ASSERT_UNSPEC;
  try {
    node->lvalue()->accept(this, lvl);
    node->type(node->lvalue()->type());
  } catch (const std::string &id) {
    throw "undeclared variable '" + id + "'";
  }
}

void udf::type_checker::do_assignment_node(cdk::assignment_node *const node, int lvl) {
  ASSERT_UNSPEC;

  node->lvalue()->accept(this, lvl + 4);
  node->rvalue()->accept(this, lvl + 4);

  if (node->lvalue()->is_typed(cdk::TYPE_INT)) {
    if (node->rvalue()->is_typed(cdk::TYPE_INT)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
      node->rvalue()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    } else {
      throw std::string("wrong assignment to integer");
    }
  } else if (node->lvalue()->is_typed(cdk::TYPE_POINTER)) {
    if (node->rvalue()->is_typed(cdk::TYPE_POINTER)) {
      node->type(node->rvalue()->type());
    } else if (node->rvalue()->is_typed(cdk::TYPE_INT)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_POINTER));
    } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_ERROR));
      node->rvalue()->type(cdk::primitive_type::create(4, cdk::TYPE_ERROR));
    } else {
      throw std::string("wrong assignment to pointer");
    }

  } else if (node->lvalue()->is_typed(cdk::TYPE_TENSOR)) {
    if (node->rvalue()->is_typed(cdk::TYPE_TENSOR)) {
      node->type(node->rvalue()->type());
    } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
      node->type(node->lvalue()->type());
      node->rvalue()->type(node->lvalue()->type());
    } else {
      throw std::string("wrong assignment to tensor");
    }

  } else if (node->lvalue()->is_typed(cdk::TYPE_DOUBLE)) {

    if (node->rvalue()->is_typed(cdk::TYPE_DOUBLE) || node->rvalue()->is_typed(cdk::TYPE_INT)) {
      node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
    } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
      node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
      node->rvalue()->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
    } else {
      throw std::string("wrong assignment to real");
    }

  } else if (node->lvalue()->is_typed(cdk::TYPE_STRING)) {

    if (node->rvalue()->is_typed(cdk::TYPE_STRING)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
    } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
      node->rvalue()->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
    } else {
      throw std::string("wrong assignment to string");
    }

  } else if (node->lvalue()->is_typed(cdk::TYPE_FUNCTIONAL)) {

    if (node->rvalue()->is_typed(cdk::TYPE_FUNCTIONAL)) {
      node->type(node->lvalue()->type());
      // TODO check types
    } else {
      throw std::string("wrong assignment to function pointer");
    }

  } else {
    throw std::string("wrong types in assignment");
  }
}

//---------------------------------------------------------------------------

void udf::type_checker::do_evaluation_node(udf::evaluation_node *const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
}

void udf::type_checker::do_print_node(udf::print_node *const node, int lvl) {
  node->arguments()->accept(this, lvl + 2);
}

void udf::type_checker::do_input_node(udf::input_node * const node, int lvl) {
  node->type(cdk::primitive_type::create(0, cdk::TYPE_UNSPEC));
}

//---------------------------------------------------------------------------

void udf::type_checker::do_for_node(udf::for_node *const node, int lvl) {
  _symtab.push();
  node->init()->accept(this, lvl + 2);
  node->condition()->accept(this, lvl + 2);
  for (size_t ix = 0; ix < node->condition()->size(); ix++) {
    cdk::expression_node *elem = dynamic_cast<cdk::expression_node*>(node->condition()->node(ix));
    elem->accept(this, lvl + 2);
    if (!elem->is_typed(cdk::TYPE_INT)) {
      throw std::string("wrong condition type in for statement (integer expected).");
    }
  }
  node->step()->accept(this, lvl + 2);
  if (node->block()) {
    node->block()->accept(this, lvl + 2);
  }
  _symtab.pop();
}

//---------------------------------------------------------------------------

void udf::type_checker::do_if_node(udf::if_node *const node, int lvl) {
  node->condition()->accept(this, lvl + 2);
  if (!node->condition()->is_typed(cdk::TYPE_INT)) throw std::string("expected integer condition");
}

void udf::type_checker::do_if_else_node(udf::if_else_node *const node, int lvl) {
  node->condition()->accept(this, lvl + 2);
  if (!node->condition()->is_typed(cdk::TYPE_INT)) throw std::string("expected integer condition");
}

//---------------------------------------------------------------------------

void udf::type_checker::do_variable_declaration_node(udf::variable_declaration_node * const node, int lvl) {
  if (node->initializer() != nullptr) {
    node->initializer()->accept(this, lvl + 2);
    if (node->type()== nullptr){
      node->type(node->initializer()->type()); // auto type 
    } 

    if (node->is_typed(cdk::TYPE_INT)) {
      if (!node->initializer()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type for initializer (integer expected).");
    } else if (node->is_typed(cdk::TYPE_DOUBLE)) {
      if (!node->initializer()->is_typed(cdk::TYPE_INT) && !node->initializer()->is_typed(cdk::TYPE_DOUBLE)) {
        throw std::string("wrong type for initializer (integer or double expected).");
      }
    } else if (node->is_typed(cdk::TYPE_STRING)) {
      if (!node->initializer()->is_typed(cdk::TYPE_STRING)) {
        throw std::string("wrong type for initializer (string expected).");
      }
    } else if (node->is_typed(cdk::TYPE_POINTER)) {
      if (!node->initializer()->is_typed(cdk::TYPE_POINTER)) {
        auto in = (cdk::literal_node<int>*)node->initializer();
        if (in == nullptr || in->value() != 0) throw std::string("wrong type for initializer (pointer expected).");
      }
    } else if (node->is_typed(cdk::TYPE_TENSOR)) {
      if (!node->initializer()->is_typed(cdk::TYPE_TENSOR)) {
        throw std::string("wrong type for initializer (tensor expected).");
      }
    } else {
      throw std::string("unknown type for initializer.");
    }
  }

  const std::string &id = node->identifier();
  auto symbol = udf::make_symbol(false, node->qualifier(), node->type(), id, (bool)node->initializer(), false);
  if (_symtab.insert(id, symbol)) {
    _parent->set_new_symbol(symbol);  // advise parent that a symbol has been inserted
  } else {
    throw std::string("variable '" + id + "' redeclared");
  }
}

//---------------------------------------------------------------------------
//protected:
std::vector<size_t> udf::type_checker::extract_dims(cdk::sequence_node *const elements, int lvl) {
  if (elements->size() == 0)
    throw std::string("tensor cannot be empty.");

  std::vector<size_t> dims;
  dims.push_back(elements->size());
  std::vector<size_t> inner_dims;
  std::shared_ptr<cdk::basic_type> common_type;

  for (size_t ix = 0; ix < elements->size(); ix++) {
    cdk::expression_node *elem = dynamic_cast<cdk::expression_node*>(elements->node(ix));
    elem->accept(this, lvl + 2);

    auto *tensor_elem = dynamic_cast<udf::tensor_node*>(elem);
    if (tensor_elem) {
      auto nested_dims = extract_dims(tensor_elem->elements(), lvl + 2);
      if (!inner_dims.empty() && inner_dims != nested_dims) {
        throw std::string("inconsistent nested tensor dimensions.");
      }
      inner_dims = nested_dims;
    } else {
      if (!elem->is_typed(cdk::TYPE_INT) && !elem->is_typed(cdk::TYPE_DOUBLE)) {
        throw std::string("wrong type for tensor element (integer or double expected).");
      }
      if (!common_type)
        common_type = elem->type();
      else if ((common_type->name() == cdk::TYPE_INT && elem->is_typed(cdk::TYPE_DOUBLE))) {
        common_type = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE);
      }
    }
  }

  dims.insert(dims.end(), inner_dims.begin(), inner_dims.end());
  return dims;
}

//---------------------------------------------------------------------------

void udf::type_checker::do_tensor_node(udf::tensor_node * const node, int lvl) {
  ASSERT_UNSPEC;
  auto dims = extract_dims(node->elements(), lvl);
  node->type(cdk::tensor_type::create(dims));
}

void udf::type_checker::do_tensor_capacity_node(udf::tensor_capacity_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  if (!node->argument()->is_typed(cdk::TYPE_TENSOR)) {
    throw std::string("tensor expression expected in tensor capacity operation");
  }
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void udf::type_checker::do_tensor_rank_node(udf::tensor_rank_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  if (!node->argument()->is_typed(cdk::TYPE_TENSOR)) {
    throw std::string("tensor expression expected in tensor rank operation");
  }
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void udf::type_checker::do_tensor_dimensions_node(udf::tensor_dimensions_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  if (!node->argument()->is_typed(cdk::TYPE_TENSOR)) {
    throw std::string("tensor expression expected in tensor dimensions operation");
  }
  node->type(cdk::reference_type::create(4, cdk::primitive_type::create(4, cdk::TYPE_INT)));
}

void udf::type_checker::do_tensor_dimension_node(udf::tensor_dimension_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->tensor()->accept(this, lvl + 2);
  node->index()->accept(this, lvl + 2);
  if (!node->tensor()->is_typed(cdk::TYPE_TENSOR)) {
    throw std::string("tensor expression expected in tensor dimension operation");
  } else if (!node->index()->is_typed(cdk::TYPE_INT)) {
    throw std::string("wrong index type in tensor dimension operation (integer expected).");
  }

  auto tensor_type = cdk::tensor_type::cast(node->tensor()->type());
  auto index = (cdk::literal_node<int>*)node->index();
  if (index->value() < 0 || static_cast<size_t>(index->value()) >= tensor_type->n_dims()) {
    throw std::string("index out of bounds in tensor dimension operation.");
  }

  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void udf::type_checker::do_tensor_index_node(udf::tensor_index_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->tensor()->accept(this, lvl + 2);
  node->index()->accept(this, lvl + 2);
  if (!node->tensor()->is_typed(cdk::TYPE_TENSOR)) {
    throw std::string("tensor expression expected in tensor indexation operation.");
  }

  auto tensor_type = cdk::tensor_type::cast(node->tensor()->type());
  if (node->index()->size() != tensor_type->n_dims()) {
    throw std::string("wrong index in tensor indexation operation (mismateched dimensions).");
  }

  for (size_t ix = 0; ix < node->index()->size(); ix++) {
    cdk::expression_node *elem = dynamic_cast<cdk::expression_node*>(node->index()->node(ix));
    elem->accept(this, lvl + 4);
    if (!elem->is_typed(cdk::TYPE_INT)) {
      throw std::string("wrong index type in tensor dimension operation (integer expressions expected).");
    }

    tensor_type->dim(ix);
    auto coord = dynamic_cast<cdk::literal_node<int> *>(elem);
    int value = coord->value();
    if (value < 0 || static_cast<size_t>(value) >= tensor_type->dim(ix)) {
      throw std::string("index out of bounds in tensor indexation operation.");
    }
  }

  node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
}

void udf::type_checker::do_tensor_reshape_node(udf::tensor_reshape_node * const node, int lvl) {
  node->tensor()->accept(this, lvl);
  if (!node->tensor()->is_typed(cdk::TYPE_TENSOR)) {
    throw std::string("reshape only applicable to tensors");
  }

  auto ttype = cdk::tensor_type::cast(node->tensor()->type());

  size_t new_total = 1;
  std::vector<size_t> new_dims;
  for (size_t i = 0; i < node->new_shape()->size(); i++) {
    cdk::expression_node *elem = dynamic_cast<cdk::expression_node*>(node->new_shape()->node(i));
    elem->accept(this, lvl + 2);
    if (!elem->is_typed(cdk::TYPE_INT)){
      throw std::string("reshape: dimensions must be integer literals");
    }
    auto expr = dynamic_cast<cdk::literal_node<int> *>(elem);
    int value = expr->value();
    if (value <= 0) {
      throw std::string("reshape: dimension must be > 0");
    }

    new_dims.push_back(value);
    new_total *= value;
  }

  size_t old_total = 1;
  for (size_t dim : ttype->dims()) old_total *= dim;

  if (old_total != new_total) {
    throw std::string("reshape must preserve number of elements");
  }

  node->type(cdk::tensor_type::create(new_dims));
}

void udf::type_checker::do_tensor_contraction_node(udf::tensor_contraction_node * const node, int lvl) {
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);

  auto left_type = cdk::tensor_type::cast(node->left()->type());
  auto right_type = cdk::tensor_type::cast(node->right()->type());

  if (!left_type || !right_type) {
    throw std::string("tensor contraction requires tensor operands");
  }

  size_t n_dims_left = left_type->n_dims();
  size_t n_dims_right = right_type->n_dims();

  const std::vector<size_t> &left_dims = left_type->dims();
  const std::vector<size_t> &right_dims = right_type->dims();

  // Ensure at least 1 dimension in each
  if (n_dims_left < 1 || n_dims_right < 1) {
    throw std::string("tensor contraction requires at least 1 dimension on each tensor");
  }

  // Ensure last dim of t1 == first dim of t2
  if (left_dims[n_dims_left - 1] != right_dims[0]) {
    throw std::string("tensor contraction mismatch: left last dim != right first dim");
  }

  std::vector<size_t> dims;
  for (size_t i = 0; i < left_type->n_dims() - 1; ++i)
    dims.push_back(left_type->dims()[i]);
  for (size_t i = 1; i < right_type->n_dims(); ++i)
    dims.push_back(right_type->dims()[i]);
  
  node->type(cdk::tensor_type::create(dims));
}

//---------------------------------------------------------------------------

void udf::type_checker::do_break_node(udf::break_node * const node, int lvl) {
  // EMPTY
}

void udf::type_checker::do_continue_node(udf::continue_node * const node, int lvl) {
  // EMPTY
}

void udf::type_checker::do_return_node(udf::return_node * const node, int lvl) {
  if (node->retval() != nullptr) node->retval()->accept(this, lvl);
}

//---------------------------------------------------------------------------

void udf::type_checker::do_function_declaration_node(udf::function_declaration_node *const node, int lvl) {
  std::string id;

  if (node->identifier() == "udf")
    id = "_main";
  else if (node->identifier() == "_main")
    id = "._main";
  else
    id = node->identifier();

  // remember symbol so that args know
  auto function = udf::make_symbol(false, node->qualifier(), node->type(), id, false, true, true);

  std::shared_ptr<udf::symbol> previous = _symtab.find(function->name());
  if (previous) {
    if (false) {
      throw std::string("conflicting declaration for '" + function->name() + "'");
    }
  } else {
    _symtab.insert(function->name(), function);
    _parent->set_new_symbol(function);
  }
}

void udf::type_checker::do_function_definition_node(udf::function_definition_node *const node, int lvl) {
  std::string id;

  //"fix" naming issues...
  if (node->identifier() == "udf")
    id = "_main";
  else if (node->identifier() == "_main")
    id = "._main";
  else
    id = node->identifier();

  _inBlockReturnType = nullptr;

  //remember symbol so that args know
  auto function = udf::make_symbol(false, node->qualifier(), node->type(), id, false, true);

  std::shared_ptr<udf::symbol> previous = _symtab.find(function->name());
  if (previous) {
    if (previous->forward()
        && ((previous->qualifier() == tPUBLIC && node->qualifier() == tPUBLIC)
            || (previous->qualifier() == tPRIVATE && node->qualifier() == tPRIVATE))) {
      _symtab.replace(function->name(), function);
      _parent->set_new_symbol(function);
    } else {
      throw std::string("conflicting definition for '" + function->name() + "'");
    }
  } else {
    _symtab.insert(function->name(), function);
    _parent->set_new_symbol(function);
  }

}

void udf::type_checker::do_function_call_node(udf::function_call_node *const node, int lvl) {
  ASSERT_UNSPEC;

  const std::string &id = node->identifier();
  auto symbol = _symtab.find(id);
  if (symbol == nullptr) throw std::string("symbol '" + id + "' is undeclared.");
  if (!symbol->is_typed(cdk::TYPE_FUNCTIONAL)) throw std::string("symbol '" + id + "' is not a function.");

  auto function_type = cdk::functional_type::cast(symbol->type());
  node->type(function_type->output(0));  // only one output type (single value)

  if (node->arguments()->size() == function_type->input_length()) {
    node->arguments()->accept(this, lvl + 2);
    for (size_t ax = 0; ax < node->arguments()->size(); ax++) {
      if (node->argument(ax)->type() == function_type->input(ax)) continue;
      if (function_type->input(ax)->name() == cdk::TYPE_DOUBLE && node->argument(ax)->is_typed(cdk::TYPE_INT)) continue;
      throw std::string("type mismatch for argument " + std::to_string(ax + 1) + " of '" + id + "'.");
    }
  } else {
    throw std::string(
        "number of arguments in call (" + std::to_string(node->arguments()->size()) + ") must match declaration ("
            + std::to_string(function_type->input_length()) + ").");
  }
}

void udf::type_checker::do_unless_node(udf::unless_node *const node, int lvl) {
  node->condition()->accept(this, lvl + 2);
  node->vector()->accept(this, lvl + 2);
  node->count()->accept(this, lvl + 2);

  if (node->condition()->is_typed(cdk::TYPE_UNSPEC)) {
    node->condition()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else if (!node->condition()->is_typed(cdk::TYPE_INT)) {
    throw std::string("wrong type in condition of unless statement (integer expected).");
  }

  if (!node->vector()->is_typed(cdk::TYPE_POINTER)) {
    throw std::string("wrong type in vector of unless statement (pointer expected).");
  }

  if (node->count()->is_typed(cdk::TYPE_UNSPEC)) {
    node->count()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else if (!node->count()->is_typed(cdk::TYPE_INT)) {
    throw std::string("wrong type in count of unless statement (integer expected).");
  }

  const std::string &id = node->function();
  auto symbol = _symtab.find(id);

  if (symbol == nullptr) throw std::string("symbol '" + id + "' is undeclared.");
  if (!symbol->is_typed(cdk::TYPE_FUNCTIONAL)) throw std::string("symbol '" + id + "' is not a function.");

  auto function_type = cdk::functional_type::cast(symbol->type());
  auto vector_type = cdk::reference_type::cast(node->vector()->type());
  auto count = (cdk::literal_node<int>*)node->count();

  if (static_cast<int>(function_type->input_length()) != count->value()) {
    throw std::string("function type must have the same number of arguments as count in unless statement.");
  } else {
    for (size_t ax = 0; ax < function_type->input_length(); ax++) {
      if (function_type->input(ax)->name() == cdk::TYPE_POINTER && vector_type->referenced()->name() == cdk::TYPE_POINTER) {
        // check that pointer types are compatible recursively
        // if they are compatible, continue
        continue;
      } else if (function_type->input(ax)->name() == cdk::TYPE_TENSOR && vector_type->referenced()->name() == cdk::TYPE_TENSOR) {
        if (cdk::tensor_type::cast(function_type->input(ax))->dims() == cdk::tensor_type::cast(vector_type->referenced())->dims()) continue;
      }
      if (vector_type->referenced() == function_type->input(ax)) continue;
      if (function_type->input(ax)->name() == cdk::TYPE_DOUBLE && vector_type->referenced()->name() == cdk::TYPE_INT) continue;
      throw std::string("type mismatch for argument " + std::to_string(ax + 1) + " of '" + id + "'.");
    }
  }
}