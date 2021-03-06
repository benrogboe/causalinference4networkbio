// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#ifndef RCPP_Scribe_RCPPEXPORTS_H_GEN_
#define RCPP_Scribe_RCPPEXPORTS_H_GEN_

#include <RcppArmadillo.h>
#include <Rcpp.h>

namespace Scribe {

    using namespace Rcpp;

    namespace {
        void validateSignature(const char* sig) {
            Rcpp::Function require = Rcpp::Environment::base_env()["require"];
            require("Scribe", Rcpp::Named("quietly") = true);
            typedef int(*Ptr_validate)(const char*);
            static Ptr_validate p_validate = (Ptr_validate)
                R_GetCCallable("Scribe", "_Scribe_RcppExport_validate");
            if (!p_validate(sig)) {
                throw Rcpp::function_not_exported(
                    "C++ function with signature '" + std::string(sig) + "' not found in Scribe");
            }
        }
    }

    inline NumericMatrix kde_cpp(NumericMatrix data, int k = 1, int b = 1, int pdf = 1, int density_sample_type = 1) {
        typedef SEXP(*Ptr_kde_cpp)(SEXP,SEXP,SEXP,SEXP,SEXP);
        static Ptr_kde_cpp p_kde_cpp = NULL;
        if (p_kde_cpp == NULL) {
            validateSignature("NumericMatrix(*kde_cpp)(NumericMatrix,int,int,int,int)");
            p_kde_cpp = (Ptr_kde_cpp)R_GetCCallable("Scribe", "_Scribe_kde_cpp");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_kde_cpp(Shield<SEXP>(Rcpp::wrap(data)), Shield<SEXP>(Rcpp::wrap(k)), Shield<SEXP>(Rcpp::wrap(b)), Shield<SEXP>(Rcpp::wrap(pdf)), Shield<SEXP>(Rcpp::wrap(density_sample_type)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<NumericMatrix >(rcpp_result_gen);
    }

    inline NumericMatrix kde(SEXP data, SEXP k, SEXP b, SEXP pdf, SEXP density_sample_type) {
        typedef SEXP(*Ptr_kde)(SEXP,SEXP,SEXP,SEXP,SEXP);
        static Ptr_kde p_kde = NULL;
        if (p_kde == NULL) {
            validateSignature("NumericMatrix(*kde)(SEXP,SEXP,SEXP,SEXP,SEXP)");
            p_kde = (Ptr_kde)R_GetCCallable("Scribe", "_Scribe_kde");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_kde(Shield<SEXP>(Rcpp::wrap(data)), Shield<SEXP>(Rcpp::wrap(k)), Shield<SEXP>(Rcpp::wrap(b)), Shield<SEXP>(Rcpp::wrap(pdf)), Shield<SEXP>(Rcpp::wrap(density_sample_type)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<NumericMatrix >(rcpp_result_gen);
    }

    inline List knn_density(SEXP x, SEXP y, SEXP k) {
        typedef SEXP(*Ptr_knn_density)(SEXP,SEXP,SEXP);
        static Ptr_knn_density p_knn_density = NULL;
        if (p_knn_density == NULL) {
            validateSignature("List(*knn_density)(SEXP,SEXP,SEXP)");
            p_knn_density = (Ptr_knn_density)R_GetCCallable("Scribe", "_Scribe_knn_density");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_knn_density(Shield<SEXP>(Rcpp::wrap(x)), Shield<SEXP>(Rcpp::wrap(y)), Shield<SEXP>(Rcpp::wrap(k)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<List >(rcpp_result_gen);
    }

    inline NumericMatrix knn_density_2d(SEXP x, SEXP y, SEXP nGrids, SEXP k) {
        typedef SEXP(*Ptr_knn_density_2d)(SEXP,SEXP,SEXP,SEXP);
        static Ptr_knn_density_2d p_knn_density_2d = NULL;
        if (p_knn_density_2d == NULL) {
            validateSignature("NumericMatrix(*knn_density_2d)(SEXP,SEXP,SEXP,SEXP)");
            p_knn_density_2d = (Ptr_knn_density_2d)R_GetCCallable("Scribe", "_Scribe_knn_density_2d");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_knn_density_2d(Shield<SEXP>(Rcpp::wrap(x)), Shield<SEXP>(Rcpp::wrap(y)), Shield<SEXP>(Rcpp::wrap(nGrids)), Shield<SEXP>(Rcpp::wrap(k)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<NumericMatrix >(rcpp_result_gen);
    }

    inline double digamma_0(double x) {
        typedef SEXP(*Ptr_digamma_0)(SEXP);
        static Ptr_digamma_0 p_digamma_0 = NULL;
        if (p_digamma_0 == NULL) {
            validateSignature("double(*digamma_0)(double)");
            p_digamma_0 = (Ptr_digamma_0)R_GetCCallable("Scribe", "_Scribe_digamma_0");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_digamma_0(Shield<SEXP>(Rcpp::wrap(x)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<double >(rcpp_result_gen);
    }

    inline double vd(SEXP d) {
        typedef SEXP(*Ptr_vd)(SEXP);
        static Ptr_vd p_vd = NULL;
        if (p_vd == NULL) {
            validateSignature("double(*vd)(SEXP)");
            p_vd = (Ptr_vd)R_GetCCallable("Scribe", "_Scribe_vd");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_vd(Shield<SEXP>(Rcpp::wrap(d)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<double >(rcpp_result_gen);
    }

    inline double entropy(SEXP x, SEXP k) {
        typedef SEXP(*Ptr_entropy)(SEXP,SEXP);
        static Ptr_entropy p_entropy = NULL;
        if (p_entropy == NULL) {
            validateSignature("double(*entropy)(SEXP,SEXP)");
            p_entropy = (Ptr_entropy)R_GetCCallable("Scribe", "_Scribe_entropy");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_entropy(Shield<SEXP>(Rcpp::wrap(x)), Shield<SEXP>(Rcpp::wrap(k)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<double >(rcpp_result_gen);
    }

    inline double mi(SEXP x, SEXP y, SEXP k, SEXP normalize) {
        typedef SEXP(*Ptr_mi)(SEXP,SEXP,SEXP,SEXP);
        static Ptr_mi p_mi = NULL;
        if (p_mi == NULL) {
            validateSignature("double(*mi)(SEXP,SEXP,SEXP,SEXP)");
            p_mi = (Ptr_mi)R_GetCCallable("Scribe", "_Scribe_mi");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_mi(Shield<SEXP>(Rcpp::wrap(x)), Shield<SEXP>(Rcpp::wrap(y)), Shield<SEXP>(Rcpp::wrap(k)), Shield<SEXP>(Rcpp::wrap(normalize)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<double >(rcpp_result_gen);
    }

    inline List cmi(SEXP x, SEXP y, SEXP z, SEXP k, SEXP normalize) {
        typedef SEXP(*Ptr_cmi)(SEXP,SEXP,SEXP,SEXP,SEXP);
        static Ptr_cmi p_cmi = NULL;
        if (p_cmi == NULL) {
            validateSignature("List(*cmi)(SEXP,SEXP,SEXP,SEXP,SEXP)");
            p_cmi = (Ptr_cmi)R_GetCCallable("Scribe", "_Scribe_cmi");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_cmi(Shield<SEXP>(Rcpp::wrap(x)), Shield<SEXP>(Rcpp::wrap(y)), Shield<SEXP>(Rcpp::wrap(z)), Shield<SEXP>(Rcpp::wrap(k)), Shield<SEXP>(Rcpp::wrap(normalize)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<List >(rcpp_result_gen);
    }

    inline List ucmi_cpp(const NumericMatrix& x, const NumericMatrix& y, NumericMatrix z, int k, int method, int k_density, double bw) {
        typedef SEXP(*Ptr_ucmi_cpp)(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP);
        static Ptr_ucmi_cpp p_ucmi_cpp = NULL;
        if (p_ucmi_cpp == NULL) {
            validateSignature("List(*ucmi_cpp)(const NumericMatrix&,const NumericMatrix&,NumericMatrix,int,int,int,double)");
            p_ucmi_cpp = (Ptr_ucmi_cpp)R_GetCCallable("Scribe", "_Scribe_ucmi_cpp");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_ucmi_cpp(Shield<SEXP>(Rcpp::wrap(x)), Shield<SEXP>(Rcpp::wrap(y)), Shield<SEXP>(Rcpp::wrap(z)), Shield<SEXP>(Rcpp::wrap(k)), Shield<SEXP>(Rcpp::wrap(method)), Shield<SEXP>(Rcpp::wrap(k_density)), Shield<SEXP>(Rcpp::wrap(bw)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<List >(rcpp_result_gen);
    }

    inline List ucmi(SEXP x, SEXP y, SEXP z, SEXP k, SEXP method, SEXP k_density, SEXP bw) {
        typedef SEXP(*Ptr_ucmi)(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP);
        static Ptr_ucmi p_ucmi = NULL;
        if (p_ucmi == NULL) {
            validateSignature("List(*ucmi)(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP)");
            p_ucmi = (Ptr_ucmi)R_GetCCallable("Scribe", "_Scribe_ucmi");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_ucmi(Shield<SEXP>(Rcpp::wrap(x)), Shield<SEXP>(Rcpp::wrap(y)), Shield<SEXP>(Rcpp::wrap(z)), Shield<SEXP>(Rcpp::wrap(k)), Shield<SEXP>(Rcpp::wrap(method)), Shield<SEXP>(Rcpp::wrap(k_density)), Shield<SEXP>(Rcpp::wrap(bw)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<List >(rcpp_result_gen);
    }

    inline double umi_cpp(const NumericMatrix& x, const NumericMatrix& y, int k, int method, int k_density, double bw) {
        typedef SEXP(*Ptr_umi_cpp)(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP);
        static Ptr_umi_cpp p_umi_cpp = NULL;
        if (p_umi_cpp == NULL) {
            validateSignature("double(*umi_cpp)(const NumericMatrix&,const NumericMatrix&,int,int,int,double)");
            p_umi_cpp = (Ptr_umi_cpp)R_GetCCallable("Scribe", "_Scribe_umi_cpp");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_umi_cpp(Shield<SEXP>(Rcpp::wrap(x)), Shield<SEXP>(Rcpp::wrap(y)), Shield<SEXP>(Rcpp::wrap(k)), Shield<SEXP>(Rcpp::wrap(method)), Shield<SEXP>(Rcpp::wrap(k_density)), Shield<SEXP>(Rcpp::wrap(bw)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<double >(rcpp_result_gen);
    }

    inline double umi(SEXP x, SEXP y, SEXP k, SEXP method, SEXP k_density, SEXP bw) {
        typedef SEXP(*Ptr_umi)(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP);
        static Ptr_umi p_umi = NULL;
        if (p_umi == NULL) {
            validateSignature("double(*umi)(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP)");
            p_umi = (Ptr_umi)R_GetCCallable("Scribe", "_Scribe_umi");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_umi(Shield<SEXP>(Rcpp::wrap(x)), Shield<SEXP>(Rcpp::wrap(y)), Shield<SEXP>(Rcpp::wrap(k)), Shield<SEXP>(Rcpp::wrap(method)), Shield<SEXP>(Rcpp::wrap(k_density)), Shield<SEXP>(Rcpp::wrap(bw)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<double >(rcpp_result_gen);
    }

}

#endif // RCPP_Scribe_RCPPEXPORTS_H_GEN_
