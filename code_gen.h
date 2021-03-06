#ifndef CODE_GEN_H
#define CODE_GEN_H

#include <vector>
#include "classes.h"
#include "shared.h"
#include "control_flow.h"

class range_list
{
    public:
    range_t *r;
    range_list *next;
};

bool va_is_pound(variable_access_t* va);
void gen_code_for_non_attr_function_call(Statement *stat, BasicBlock* current_bb);
void code_generation(struct program_t *program);
void gen_code_for_bbs(std::vector<BasicBlock*> cfg, bool is_main);
void gen_code_for_bb(BasicBlock* current_bb, bool is_main);
void gen_code_for_return_from_func(Statement* stat);
void gen_code_for_bb_stats(std::vector<Statement*> statements, BasicBlock* current_bb);
void push_stack();
void add_ra_code_and_to_stack(BasicBlock* bb);
void add_object_location_to_stack(variable_access_t *va);
string get_num_from_primary(primary_t* p, int sign);
string get_num_from_factor(factor_t *f);
string get_num_from_expr(expression_t* e);
string retrieve_offset_for_param_expr(expression_t *e, string param_type);
string retrieve_value_for_param_expr(expression_t *e, string param_type);
int add_params_to_stack(actual_parameter_list_t *apl, FuncNode* func);
void prepare_stack_for_function_call(variable_access_t* va, BasicBlock* current_bb, FuncNode* func);
std::tuple<ClassNode*, FuncNode*> get_class_and_func_node_for_func_call(variable_access_t* va);
void init_local_vars(FuncNode *function);
void reset_stack_from_function_call(FuncNode* function);
void gen_code_for_class_function_call(Statement *stat, BasicBlock* current_bb);
void gen_code_for_new_stat(Statement* stat);
void gen_code_for_goto(Statement* stat);
void gen_code_for_print(Statement* stat);
std::vector<string> retrieve_offset_for_rhs(RHS* rhs);
bool lhs_is_tmp_var(variable_access_t *lhs);
string get_type_from_rhs(RHS *rhs);
string get_type_from_va(variable_access_t *va);
void gen_code_for_assign(Statement* stat);
void pop_tmp_vars_off_stack();
void check_and_pop_tmp_var(Term *tmp, int cl_size);
string get_str_from_stat_op(int op_num);
tuple<string,string> get_offset_and_class_for_va_id(char *va);
tuple<string,string> get_offset_and_class_for_attr_des(attribute_designator_t *attr);
VarNode* get_var_node_from_class(string class_name, string attr_name);
ClassNode* look_up_class(string class_name);
VarNode* look_up_temp_var(string var_name);
VarNode* add_tmp_var_to_stack(string var_name, string type);
bool is_number(const std::string& s);
string get_offset_for_expr(indexed_variable_t *iv, range_list *r, int current_size, string offset);
string strip_outer_mem(string offset);
tuple<string,string> get_offset_and_class_for_index_var(indexed_variable_t *iv, range_list *r, int current_size);
void print_range_list(range_list *range);
range_list *create_range_list(array_type_t* array);
string get_var_name_from_iv(indexed_variable_t* iv);
string find_attr_name_of_indexed_var(indexed_variable_t *iv);
string find_class_of_indexed_var(indexed_variable_t* iv);
array_type_t *find_array_for_iv(indexed_variable_t* iv);
tuple<string,string> retrieve_offset_for_va(variable_access_t *va);
std::vector<VarNode*> convert_c_structs_to_classes(char *id, ClassNode_c *cnode_list, int offset, class_list_t *class_list);
ClassNode* _convert_to_class(ClassNode_c *cnode, int starting_offset, bool is_global, class_list_t* cl);
std::vector<VarNode*> create_param_var_nodes(formal_parameter_section_list_t *fpsl);
std::vector<FuncNode*> create_function_nodes(func_declaration_list_t *fdl, bool is_global, string name);
std::vector<VarNode*> copy_var_nodes(std::vector<VarNode*> attr_nodes);
std::vector<VarNode*> convert_attribute_structs(VarNode_c *attr_structs, int starting_offset, bool is_global);
int get_class_size(string _class);
ClassNode *find_classmap(string parent);
std::vector<VarNode*> convert_c_structs_for_main(ClassNode_c *cnode_list, class_list_t *cl);
void init_var_table(std::vector<VarNode*> vnodes);
void init_global_region(std::vector<VarNode*> vnodes);
void populate_label_array(int bb_num);
void initial_setup();
void add_primitives_to_class_table();
identifier_list_t* reverse_id_list(identifier_list_t* idl);
formal_parameter_section_list_t* reverse_fpsl(formal_parameter_section_list_t *fpsl);
class_list_t * reverse_class_list(class_list_t* cl_orig);
void print_global_var_table();
void print_array(array_type_t *array, string type);
void print_cpp_classes();
string gen_right_var_offset_based_on_scope(VarNode* var);
bool va_is_this(variable_access_t* va);


/*NOT FOUND*/
VarNode* look_up_global_var(string var_name);






#endif