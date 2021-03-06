% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{di_single_run}
\alias{di_single_run}
\title{di_single_run}
\usage{
di_single_run(x, y, n, uniformalize)
}
\arguments{
\item{x}{one random variable from the time-series data}

\item{y}{another random variable from the time-series data}

\item{n}{Parameter n determines the the number of previous time samples upon which the mi is conditioned (delay in the formula I(x-->y)=I(x_{t-d};y_t|y_{t-1}) default: d=1)}

\item{uniformalize}{Whether or not you want to use ucmi to calculate rdi. Default to be false.}
}
\value{
a matrix for the condition mutual information estimators between all pairwise variables (x, y) in the data matrix x, y
}
\description{
This function estimates the DIRECTED mutual information from X to Y when you have a SINGLE run of the process
}
\details{
\code{di_single_run} takes two random variables x and y as well as a delay n to estimate the direct information between variable x and y.
}
