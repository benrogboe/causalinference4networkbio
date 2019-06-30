#include <Rcpp.h>
using namespace Rcpp;

double di_single_run_cpp(NumericMatrix& x, NumericMatrix& y, int n = 5, bool uniformalize = false); 
double di_single_run_conditioned_cpp(NumericMatrix x, NumericMatrix y, NumericMatrix& z, int n = 5, bool uniformalize = false);
double rdi_many_runs_cpp(NumericMatrix& x, NumericMatrix& y, bool uniformalize = false);
double rdi_single_run_cpp(NumericMatrix& x, NumericMatrix& y, int d = 1, bool uniformalize = false);
double lmi_single_run_cpp(NumericMatrix& x, NumericMatrix& y, int delay = 1, bool uniformalize = false) 
double lmi_multiple_run(NumericMatrix& x, NumericMatrix& y, int d = 1, IntegerVector run_vec = 0, bool uniformalize = false); 
double rdi_single_run_conditioned_cpp(NumericMatrix& x, NumericMatrix& y, NumericMatrix& z, NumericVector& z_delays, int d = 1, bool uniformalize = false);
List extract_max_rdi_value_delay(NumericMatrix rdi_result, IntegerVector delays, bool uniformalize = false)
List calculate_rdi_cpp(NumericMatrix& expr_data, IntegerVector delays, IntegerMatrix& super_graph, IntegerVector& turning_points, int method, bool uniformalize = false) //, method: 1 rdi; 2: lmi 
List extract_top_incoming_nodes_delays(NumericMatrix max_rdi_value, IntegerMatrix max_rdi_delays, int k = 1)
NumericMatrix calculate_conditioned_rdi_cpp(NumericMatrix& expr_data, IntegerMatrix& super_graph, 
                                            NumericMatrix& max_rdi_value, IntegerMatrix& max_rdi_delays, int k = 5, bool uniformalize = false);
NumericMatrix smooth_gene(NumericMatrix expr_data, const int window_size  = 40);
double rdi_multiple_run_cpp(NumericMatrix& x, NumericMatrix& y, int d = 1, IntegerVector run_vec = 0, bool uniformalize = false); 
List calculate_rdi_multiple_run_cpp(NumericMatrix& expr_data, IntegerVector delays = 1, IntegerVector run_vec = 0, IntegerMatrix& super_graph, IntegerVector turning_points = 0, int method = 1, bool uniformalize = false); // = NULL 
NumericMatrix rdi_multiple_runs_conditioned_cpp(NumericMatrix& x, NumericMatrix& y, NumericMatrix& z, IntegerVector& z_delays, int d = 1, IntegerVector run_vec = 0, bool uniformalize = false);
NumericMatrix calculate_conditioned_rdi_multiple_run_cpp(NumericMatrix& expr_data, IntegerMatrix& super_graph, 
                                            NumericMatrix& max_rdi_value, IntegerMatrix& max_rdi_delays, IntegerVector run_vec, int k = 5, bool uniformalize = false);
NumericMatrix calculate_umi_cpp(NumericMatrix& expr_data, IntegerMatrix& super_graph, int k = 5, int method = 1, int k_density = 0, double bw = 0.0);