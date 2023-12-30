#ifndef GENERIC_CPU_HPP
#define GENERIC_CPU_HPP

#include <vector>
#include "data_structs.hpp"
#include "mpd.hpp"

void find_indices(double* t,double* x,int Nd,int Nprof,int* ind);
Chi2Vars setup_chi2_calculation(std::vector<double> M,std::vector<double> V,double Dfac,int Nd,double* d,double* t,double* s,int Nprof,double* x);
void sort_chi2_by_z_CPU(int Nloc,SimLC* LCA,SimLC* LCB,double* chi2_values);
void calculate_chi2_CPU(Chi2Vars* chi2_vars,double* chi2,SimLC* LCA,SimLC* LCB);
void bin_chi2_CPU(double* binned_chi2,double* binned_exp,Chi2SortBins* sort_struct,double* chi2_values);

#endif /* GENERIC_CPU_HPP */
