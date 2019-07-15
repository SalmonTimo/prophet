// Code generated by Stan version 2.19.1

#include <stan/model/model_header.hpp>

namespace prophet_model_namespace {

using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;

static int current_statement_begin__;

stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "stan/unix/prophet.stan");
    reader.add_event(133, 131, "end", "stan/unix/prophet.stan");
    return reader;
}

template <typename T0__, typename T1__>
Eigen::Matrix<typename boost::math::tools::promote_args<T0__, T1__>::type, Eigen::Dynamic, Eigen::Dynamic>
get_changepoint_matrix(const Eigen::Matrix<T0__, Eigen::Dynamic, 1>& t,
                           const Eigen::Matrix<T1__, Eigen::Dynamic, 1>& t_change,
                           const int& T,
                           const int& S, std::ostream* pstream__) {
    typedef typename boost::math::tools::promote_args<T0__, T1__>::type local_scalar_t__;
    typedef local_scalar_t__ fun_return_scalar_t__;
    const static bool propto__ = true;
    (void) propto__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

    int current_statement_begin__ = -1;
    try {
        {
        current_statement_begin__ = 9;
        validate_non_negative_index("A", "T", T);
        validate_non_negative_index("A", "S", S);
        Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, Eigen::Dynamic> A(T, S);
        stan::math::initialize(A, DUMMY_VAR__);
        stan::math::fill(A, DUMMY_VAR__);

        current_statement_begin__ = 10;
        validate_non_negative_index("a_row", "S", S);
        Eigen::Matrix<local_scalar_t__, 1, Eigen::Dynamic> a_row(S);
        stan::math::initialize(a_row, DUMMY_VAR__);
        stan::math::fill(a_row, DUMMY_VAR__);

        current_statement_begin__ = 11;
        int cp_idx(0);
        (void) cp_idx;  // dummy to suppress unused var warning
        stan::math::fill(cp_idx, std::numeric_limits<int>::min());


        current_statement_begin__ = 14;
        stan::math::assign(A, rep_matrix(0, T, S));
        current_statement_begin__ = 15;
        stan::math::assign(a_row, rep_row_vector(0, S));
        current_statement_begin__ = 16;
        stan::math::assign(cp_idx, 1);
        current_statement_begin__ = 19;
        for (int i = 1; i <= T; ++i) {

            current_statement_begin__ = 20;
            while (as_bool((primitive_value(logical_lte(cp_idx, S)) && primitive_value(logical_gte(get_base1(t, i, "t", 1), get_base1(t_change, cp_idx, "t_change", 1)))))) {

                current_statement_begin__ = 21;
                stan::model::assign(a_row, 
                            stan::model::cons_list(stan::model::index_uni(cp_idx), stan::model::nil_index_list()), 
                            1, 
                            "assigning variable a_row");
                current_statement_begin__ = 22;
                stan::math::assign(cp_idx, (cp_idx + 1));
            }
            current_statement_begin__ = 24;
            stan::model::assign(A, 
                        stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                        a_row, 
                        "assigning variable A");
        }
        current_statement_begin__ = 26;
        return stan::math::promote_scalar<fun_return_scalar_t__>(A);
        }
    } catch (const std::exception& e) {
        stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
        // Next line prevents compiler griping about no return
        throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
    }
}


struct get_changepoint_matrix_functor__ {
    template <typename T0__, typename T1__>
        Eigen::Matrix<typename boost::math::tools::promote_args<T0__, T1__>::type, Eigen::Dynamic, Eigen::Dynamic>
    operator()(const Eigen::Matrix<T0__, Eigen::Dynamic, 1>& t,
                           const Eigen::Matrix<T1__, Eigen::Dynamic, 1>& t_change,
                           const int& T,
                           const int& S, std::ostream* pstream__) const {
        return get_changepoint_matrix(t, t_change, T, S, pstream__);
    }
};

template <typename T0__, typename T1__, typename T2__, typename T3__>
Eigen::Matrix<typename boost::math::tools::promote_args<T0__, T1__, T2__, T3__>::type, Eigen::Dynamic, 1>
logistic_gamma(const T0__& k,
                   const T1__& m,
                   const Eigen::Matrix<T2__, Eigen::Dynamic, 1>& delta,
                   const Eigen::Matrix<T3__, Eigen::Dynamic, 1>& t_change,
                   const int& S, std::ostream* pstream__) {
    typedef typename boost::math::tools::promote_args<T0__, T1__, T2__, T3__>::type local_scalar_t__;
    typedef local_scalar_t__ fun_return_scalar_t__;
    const static bool propto__ = true;
    (void) propto__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

    int current_statement_begin__ = -1;
    try {
        {
        current_statement_begin__ = 32;
        validate_non_negative_index("gamma", "S", S);
        Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> gamma(S);
        stan::math::initialize(gamma, DUMMY_VAR__);
        stan::math::fill(gamma, DUMMY_VAR__);

        current_statement_begin__ = 33;
        validate_non_negative_index("k_s", "(S + 1)", (S + 1));
        Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> k_s((S + 1));
        stan::math::initialize(k_s, DUMMY_VAR__);
        stan::math::fill(k_s, DUMMY_VAR__);

        current_statement_begin__ = 34;
        local_scalar_t__ m_pr(DUMMY_VAR__);
        (void) m_pr;  // dummy to suppress unused var warning
        stan::math::initialize(m_pr, DUMMY_VAR__);
        stan::math::fill(m_pr, DUMMY_VAR__);


        current_statement_begin__ = 37;
        stan::math::assign(k_s, append_row(k, add(k, cumulative_sum(delta))));
        current_statement_begin__ = 40;
        stan::math::assign(m_pr, m);
        current_statement_begin__ = 41;
        for (int i = 1; i <= S; ++i) {

            current_statement_begin__ = 42;
            stan::model::assign(gamma, 
                        stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                        ((get_base1(t_change, i, "t_change", 1) - m_pr) * (1 - (get_base1(k_s, i, "k_s", 1) / get_base1(k_s, (i + 1), "k_s", 1)))), 
                        "assigning variable gamma");
            current_statement_begin__ = 43;
            stan::math::assign(m_pr, (m_pr + get_base1(gamma, i, "gamma", 1)));
        }
        current_statement_begin__ = 45;
        return stan::math::promote_scalar<fun_return_scalar_t__>(gamma);
        }
    } catch (const std::exception& e) {
        stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
        // Next line prevents compiler griping about no return
        throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
    }
}


struct logistic_gamma_functor__ {
    template <typename T0__, typename T1__, typename T2__, typename T3__>
        Eigen::Matrix<typename boost::math::tools::promote_args<T0__, T1__, T2__, T3__>::type, Eigen::Dynamic, 1>
    operator()(const T0__& k,
                   const T1__& m,
                   const Eigen::Matrix<T2__, Eigen::Dynamic, 1>& delta,
                   const Eigen::Matrix<T3__, Eigen::Dynamic, 1>& t_change,
                   const int& S, std::ostream* pstream__) const {
        return logistic_gamma(k, m, delta, t_change, S, pstream__);
    }
};

template <typename T0__, typename T1__, typename T2__, typename T3__, typename T4__, typename T5__, typename T6__>
Eigen::Matrix<typename boost::math::tools::promote_args<T0__, T1__, T2__, T3__, typename boost::math::tools::promote_args<T4__, T5__, T6__>::type>::type, Eigen::Dynamic, 1>
logistic_trend(const T0__& k,
                   const T1__& m,
                   const Eigen::Matrix<T2__, Eigen::Dynamic, 1>& delta,
                   const Eigen::Matrix<T3__, Eigen::Dynamic, 1>& t,
                   const Eigen::Matrix<T4__, Eigen::Dynamic, 1>& cap,
                   const Eigen::Matrix<T5__, Eigen::Dynamic, Eigen::Dynamic>& A,
                   const Eigen::Matrix<T6__, Eigen::Dynamic, 1>& t_change,
                   const int& S, std::ostream* pstream__) {
    typedef typename boost::math::tools::promote_args<T0__, T1__, T2__, T3__, typename boost::math::tools::promote_args<T4__, T5__, T6__>::type>::type local_scalar_t__;
    typedef local_scalar_t__ fun_return_scalar_t__;
    const static bool propto__ = true;
    (void) propto__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

    int current_statement_begin__ = -1;
    try {
        {
        current_statement_begin__ = 58;
        validate_non_negative_index("gamma", "S", S);
        Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> gamma(S);
        stan::math::initialize(gamma, DUMMY_VAR__);
        stan::math::fill(gamma, DUMMY_VAR__);


        current_statement_begin__ = 60;
        stan::math::assign(gamma, logistic_gamma(k, m, delta, t_change, S, pstream__));
        current_statement_begin__ = 61;
        return stan::math::promote_scalar<fun_return_scalar_t__>(elt_multiply(cap, inv_logit(elt_multiply(add(k, multiply(A, delta)), subtract(t, add(m, multiply(A, gamma)))))));
        }
    } catch (const std::exception& e) {
        stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
        // Next line prevents compiler griping about no return
        throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
    }
}


struct logistic_trend_functor__ {
    template <typename T0__, typename T1__, typename T2__, typename T3__, typename T4__, typename T5__, typename T6__>
        Eigen::Matrix<typename boost::math::tools::promote_args<T0__, T1__, T2__, T3__, typename boost::math::tools::promote_args<T4__, T5__, T6__>::type>::type, Eigen::Dynamic, 1>
    operator()(const T0__& k,
                   const T1__& m,
                   const Eigen::Matrix<T2__, Eigen::Dynamic, 1>& delta,
                   const Eigen::Matrix<T3__, Eigen::Dynamic, 1>& t,
                   const Eigen::Matrix<T4__, Eigen::Dynamic, 1>& cap,
                   const Eigen::Matrix<T5__, Eigen::Dynamic, Eigen::Dynamic>& A,
                   const Eigen::Matrix<T6__, Eigen::Dynamic, 1>& t_change,
                   const int& S, std::ostream* pstream__) const {
        return logistic_trend(k, m, delta, t, cap, A, t_change, S, pstream__);
    }
};

template <typename T0__, typename T1__, typename T2__, typename T3__, typename T4__, typename T5__>
Eigen::Matrix<typename boost::math::tools::promote_args<T0__, T1__, T2__, T3__, typename boost::math::tools::promote_args<T4__, T5__>::type>::type, Eigen::Dynamic, 1>
linear_trend(const T0__& k,
                 const T1__& m,
                 const Eigen::Matrix<T2__, Eigen::Dynamic, 1>& delta,
                 const Eigen::Matrix<T3__, Eigen::Dynamic, 1>& t,
                 const Eigen::Matrix<T4__, Eigen::Dynamic, Eigen::Dynamic>& A,
                 const Eigen::Matrix<T5__, Eigen::Dynamic, 1>& t_change, std::ostream* pstream__) {
    typedef typename boost::math::tools::promote_args<T0__, T1__, T2__, T3__, typename boost::math::tools::promote_args<T4__, T5__>::type>::type local_scalar_t__;
    typedef local_scalar_t__ fun_return_scalar_t__;
    const static bool propto__ = true;
    (void) propto__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

    int current_statement_begin__ = -1;
    try {

        current_statement_begin__ = 74;
        return stan::math::promote_scalar<fun_return_scalar_t__>(add(elt_multiply(add(k, multiply(A, delta)), t), add(m, multiply(A, elt_multiply(minus(t_change), delta)))));
    } catch (const std::exception& e) {
        stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
        // Next line prevents compiler griping about no return
        throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
    }
}


struct linear_trend_functor__ {
    template <typename T0__, typename T1__, typename T2__, typename T3__, typename T4__, typename T5__>
        Eigen::Matrix<typename boost::math::tools::promote_args<T0__, T1__, T2__, T3__, typename boost::math::tools::promote_args<T4__, T5__>::type>::type, Eigen::Dynamic, 1>
    operator()(const T0__& k,
                 const T1__& m,
                 const Eigen::Matrix<T2__, Eigen::Dynamic, 1>& delta,
                 const Eigen::Matrix<T3__, Eigen::Dynamic, 1>& t,
                 const Eigen::Matrix<T4__, Eigen::Dynamic, Eigen::Dynamic>& A,
                 const Eigen::Matrix<T5__, Eigen::Dynamic, 1>& t_change, std::ostream* pstream__) const {
        return linear_trend(k, m, delta, t, A, t_change, pstream__);
    }
};

class prophet_model : public prob_grad {
private:
        int T;
        int K;
        vector_d t;
        vector_d cap;
        vector_d y;
        int S;
        vector_d t_change;
        matrix_d X;
        vector_d sigmas;
        double tau;
        int trend_indicator;
        vector_d s_a;
        vector_d s_m;
        matrix_d A;
public:
    prophet_model(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }

    prophet_model(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, random_seed__, pstream__);
    }

    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;

        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning

        current_statement_begin__ = -1;

        static const char* function__ = "prophet_model_namespace::prophet_model";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        try {
            // initialize data block variables from context__
            current_statement_begin__ = 79;
            context__.validate_dims("data initialization", "T", "int", context__.to_vec());
            T = int(0);
            vals_i__ = context__.vals_i("T");
            pos__ = 0;
            T = vals_i__[pos__++];

            current_statement_begin__ = 80;
            context__.validate_dims("data initialization", "K", "int", context__.to_vec());
            K = int(0);
            vals_i__ = context__.vals_i("K");
            pos__ = 0;
            K = vals_i__[pos__++];
            check_greater_or_equal(function__, "K", K, 1);

            current_statement_begin__ = 81;
            validate_non_negative_index("t", "T", T);
            context__.validate_dims("data initialization", "t", "vector_d", context__.to_vec(T));
            t = Eigen::Matrix<double, Eigen::Dynamic, 1>(T);
            vals_r__ = context__.vals_r("t");
            pos__ = 0;
            size_t t_j_1_max__ = T;
            for (size_t j_1__ = 0; j_1__ < t_j_1_max__; ++j_1__) {
                t(j_1__) = vals_r__[pos__++];
            }

            current_statement_begin__ = 82;
            validate_non_negative_index("cap", "T", T);
            context__.validate_dims("data initialization", "cap", "vector_d", context__.to_vec(T));
            cap = Eigen::Matrix<double, Eigen::Dynamic, 1>(T);
            vals_r__ = context__.vals_r("cap");
            pos__ = 0;
            size_t cap_j_1_max__ = T;
            for (size_t j_1__ = 0; j_1__ < cap_j_1_max__; ++j_1__) {
                cap(j_1__) = vals_r__[pos__++];
            }

            current_statement_begin__ = 83;
            validate_non_negative_index("y", "T", T);
            context__.validate_dims("data initialization", "y", "vector_d", context__.to_vec(T));
            y = Eigen::Matrix<double, Eigen::Dynamic, 1>(T);
            vals_r__ = context__.vals_r("y");
            pos__ = 0;
            size_t y_j_1_max__ = T;
            for (size_t j_1__ = 0; j_1__ < y_j_1_max__; ++j_1__) {
                y(j_1__) = vals_r__[pos__++];
            }

            current_statement_begin__ = 84;
            context__.validate_dims("data initialization", "S", "int", context__.to_vec());
            S = int(0);
            vals_i__ = context__.vals_i("S");
            pos__ = 0;
            S = vals_i__[pos__++];

            current_statement_begin__ = 85;
            validate_non_negative_index("t_change", "S", S);
            context__.validate_dims("data initialization", "t_change", "vector_d", context__.to_vec(S));
            t_change = Eigen::Matrix<double, Eigen::Dynamic, 1>(S);
            vals_r__ = context__.vals_r("t_change");
            pos__ = 0;
            size_t t_change_j_1_max__ = S;
            for (size_t j_1__ = 0; j_1__ < t_change_j_1_max__; ++j_1__) {
                t_change(j_1__) = vals_r__[pos__++];
            }

            current_statement_begin__ = 86;
            validate_non_negative_index("X", "T", T);
            validate_non_negative_index("X", "K", K);
            context__.validate_dims("data initialization", "X", "matrix_d", context__.to_vec(T,K));
            X = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>(T, K);
            vals_r__ = context__.vals_r("X");
            pos__ = 0;
            size_t X_j_2_max__ = K;
            size_t X_j_1_max__ = T;
            for (size_t j_2__ = 0; j_2__ < X_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < X_j_1_max__; ++j_1__) {
                    X(j_1__, j_2__) = vals_r__[pos__++];
                }
            }

            current_statement_begin__ = 87;
            validate_non_negative_index("sigmas", "K", K);
            context__.validate_dims("data initialization", "sigmas", "vector_d", context__.to_vec(K));
            sigmas = Eigen::Matrix<double, Eigen::Dynamic, 1>(K);
            vals_r__ = context__.vals_r("sigmas");
            pos__ = 0;
            size_t sigmas_j_1_max__ = K;
            for (size_t j_1__ = 0; j_1__ < sigmas_j_1_max__; ++j_1__) {
                sigmas(j_1__) = vals_r__[pos__++];
            }

            current_statement_begin__ = 88;
            context__.validate_dims("data initialization", "tau", "double", context__.to_vec());
            tau = double(0);
            vals_r__ = context__.vals_r("tau");
            pos__ = 0;
            tau = vals_r__[pos__++];
            check_greater_or_equal(function__, "tau", tau, 0);

            current_statement_begin__ = 89;
            context__.validate_dims("data initialization", "trend_indicator", "int", context__.to_vec());
            trend_indicator = int(0);
            vals_i__ = context__.vals_i("trend_indicator");
            pos__ = 0;
            trend_indicator = vals_i__[pos__++];

            current_statement_begin__ = 90;
            validate_non_negative_index("s_a", "K", K);
            context__.validate_dims("data initialization", "s_a", "vector_d", context__.to_vec(K));
            s_a = Eigen::Matrix<double, Eigen::Dynamic, 1>(K);
            vals_r__ = context__.vals_r("s_a");
            pos__ = 0;
            size_t s_a_j_1_max__ = K;
            for (size_t j_1__ = 0; j_1__ < s_a_j_1_max__; ++j_1__) {
                s_a(j_1__) = vals_r__[pos__++];
            }

            current_statement_begin__ = 91;
            validate_non_negative_index("s_m", "K", K);
            context__.validate_dims("data initialization", "s_m", "vector_d", context__.to_vec(K));
            s_m = Eigen::Matrix<double, Eigen::Dynamic, 1>(K);
            vals_r__ = context__.vals_r("s_m");
            pos__ = 0;
            size_t s_m_j_1_max__ = K;
            for (size_t j_1__ = 0; j_1__ < s_m_j_1_max__; ++j_1__) {
                s_m(j_1__) = vals_r__[pos__++];
            }


            // initialize transformed data variables
            current_statement_begin__ = 95;
            validate_non_negative_index("A", "T", T);
            validate_non_negative_index("A", "S", S);
            A = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>(T, S);
            stan::math::fill(A, DUMMY_VAR__);

            // execute transformed data statements
            current_statement_begin__ = 96;
            stan::math::assign(A, get_changepoint_matrix(t, t_change, T, S, pstream__));

            // validate transformed data

            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 100;
            num_params_r__ += 1;
            current_statement_begin__ = 101;
            num_params_r__ += 1;
            current_statement_begin__ = 102;
            validate_non_negative_index("delta", "S", S);
            num_params_r__ += S;
            current_statement_begin__ = 103;
            num_params_r__ += 1;
            current_statement_begin__ = 104;
            validate_non_negative_index("beta", "K", K);
            num_params_r__ += K;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    ~prophet_model() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        typedef double local_scalar_t__;
        stan::io::writer<double> writer__(params_r__, params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        current_statement_begin__ = 100;
        if (!(context__.contains_r("k")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable k missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("k");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "k", "double", context__.to_vec());
        double k(0);
        k = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(k);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable k: ") + e.what()), current_statement_begin__, prog_reader__());
        }

        current_statement_begin__ = 101;
        if (!(context__.contains_r("m")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable m missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("m");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "m", "double", context__.to_vec());
        double m(0);
        m = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(m);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable m: ") + e.what()), current_statement_begin__, prog_reader__());
        }

        current_statement_begin__ = 102;
        if (!(context__.contains_r("delta")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable delta missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("delta");
        pos__ = 0U;
        validate_non_negative_index("delta", "S", S);
        context__.validate_dims("parameter initialization", "delta", "vector_d", context__.to_vec(S));
        Eigen::Matrix<double, Eigen::Dynamic, 1> delta(S);
        size_t delta_j_1_max__ = S;
        for (size_t j_1__ = 0; j_1__ < delta_j_1_max__; ++j_1__) {
            delta(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_unconstrain(delta);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable delta: ") + e.what()), current_statement_begin__, prog_reader__());
        }

        current_statement_begin__ = 103;
        if (!(context__.contains_r("sigma_obs")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable sigma_obs missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("sigma_obs");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "sigma_obs", "double", context__.to_vec());
        double sigma_obs(0);
        sigma_obs = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0, sigma_obs);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable sigma_obs: ") + e.what()), current_statement_begin__, prog_reader__());
        }

        current_statement_begin__ = 104;
        if (!(context__.contains_r("beta")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable beta missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("beta");
        pos__ = 0U;
        validate_non_negative_index("beta", "K", K);
        context__.validate_dims("parameter initialization", "beta", "vector_d", context__.to_vec(K));
        Eigen::Matrix<double, Eigen::Dynamic, 1> beta(K);
        size_t beta_j_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < beta_j_1_max__; ++j_1__) {
            beta(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_unconstrain(beta);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable beta: ") + e.what()), current_statement_begin__, prog_reader__());
        }

        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }

    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }


    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(std::vector<T__>& params_r__,
                 std::vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {

        typedef T__ local_scalar_t__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // dummy to suppress unused var warning

        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;
        try {
            stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);

            // model parameters
            current_statement_begin__ = 100;
            local_scalar_t__ k;
            (void) k;  // dummy to suppress unused var warning
            if (jacobian__)
                k = in__.scalar_constrain(lp__);
            else
                k = in__.scalar_constrain();

            current_statement_begin__ = 101;
            local_scalar_t__ m;
            (void) m;  // dummy to suppress unused var warning
            if (jacobian__)
                m = in__.scalar_constrain(lp__);
            else
                m = in__.scalar_constrain();

            current_statement_begin__ = 102;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> delta;
            (void) delta;  // dummy to suppress unused var warning
            if (jacobian__)
                delta = in__.vector_constrain(S, lp__);
            else
                delta = in__.vector_constrain(S);

            current_statement_begin__ = 103;
            local_scalar_t__ sigma_obs;
            (void) sigma_obs;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma_obs = in__.scalar_lb_constrain(0, lp__);
            else
                sigma_obs = in__.scalar_lb_constrain(0);

            current_statement_begin__ = 104;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> beta;
            (void) beta;  // dummy to suppress unused var warning
            if (jacobian__)
                beta = in__.vector_constrain(K, lp__);
            else
                beta = in__.vector_constrain(K);

            // model body

            current_statement_begin__ = 109;
            lp_accum__.add(normal_log<propto__>(k, 0, 5));
            current_statement_begin__ = 110;
            lp_accum__.add(normal_log<propto__>(m, 0, 5));
            current_statement_begin__ = 111;
            lp_accum__.add(double_exponential_log<propto__>(delta, 0, tau));
            current_statement_begin__ = 112;
            lp_accum__.add(normal_log<propto__>(sigma_obs, 0, 0.5));
            current_statement_begin__ = 113;
            lp_accum__.add(normal_log<propto__>(beta, 0, sigmas));
            current_statement_begin__ = 116;
            if (as_bool(logical_eq(trend_indicator, 0))) {

                current_statement_begin__ = 117;
                lp_accum__.add(normal_log<propto__>(y, add(elt_multiply(linear_trend(k, m, delta, t, A, t_change, pstream__), add(1, multiply(X, elt_multiply(beta, s_m)))), multiply(X, elt_multiply(beta, s_a))), sigma_obs));
            } else if (as_bool(logical_eq(trend_indicator, 1))) {

                current_statement_begin__ = 124;
                lp_accum__.add(normal_log<propto__>(y, add(elt_multiply(logistic_trend(k, m, delta, t, cap, A, t_change, S, pstream__), add(1, multiply(X, elt_multiply(beta, s_m)))), multiply(X, elt_multiply(beta, s_a))), sigma_obs));
            }

        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        lp_accum__.add(lp__);
        return lp_accum__.sum();

    } // log_prob()

    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }


    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("k");
        names__.push_back("m");
        names__.push_back("delta");
        names__.push_back("sigma_obs");
        names__.push_back("beta");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(S);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(K);
        dimss__.push_back(dims__);
    }

    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;

        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
        static const char* function__ = "prophet_model_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning

        // read-transform, write parameters
        double k = in__.scalar_constrain();
        vars__.push_back(k);

        double m = in__.scalar_constrain();
        vars__.push_back(m);

        Eigen::Matrix<double, Eigen::Dynamic, 1> delta = in__.vector_constrain(S);
        size_t delta_j_1_max__ = S;
        for (size_t j_1__ = 0; j_1__ < delta_j_1_max__; ++j_1__) {
            vars__.push_back(delta(j_1__));
        }

        double sigma_obs = in__.scalar_lb_constrain(0);
        vars__.push_back(sigma_obs);

        Eigen::Matrix<double, Eigen::Dynamic, 1> beta = in__.vector_constrain(K);
        size_t beta_j_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < beta_j_1_max__; ++j_1__) {
            vars__.push_back(beta(j_1__));
        }

        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        if (!include_tparams__ && !include_gqs__) return;

        try {
            if (!include_gqs__ && !include_tparams__) return;
            if (!include_gqs__) return;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng, params_r_vec, params_i_vec, vars_vec, include_tparams, include_gqs, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }

    static std::string model_name() {
        return "prophet_model";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "k";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "m";
        param_names__.push_back(param_name_stream__.str());
        size_t delta_j_1_max__ = S;
        for (size_t j_1__ = 0; j_1__ < delta_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "delta" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_obs";
        param_names__.push_back(param_name_stream__.str());
        size_t beta_j_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < beta_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "beta" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
        }

        if (!include_gqs__) return;
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "k";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "m";
        param_names__.push_back(param_name_stream__.str());
        size_t delta_j_1_max__ = S;
        for (size_t j_1__ = 0; j_1__ < delta_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "delta" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_obs";
        param_names__.push_back(param_name_stream__.str());
        size_t beta_j_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < beta_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "beta" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
        }

        if (!include_gqs__) return;
    }

}; // model

}  // namespace

typedef prophet_model_namespace::prophet_model stan_model;

