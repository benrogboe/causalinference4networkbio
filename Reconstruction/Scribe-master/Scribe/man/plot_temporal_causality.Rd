% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/plotting.R
\name{plot_temporal_causality}
\alias{plot_temporal_causality}
\title{Plot the temporal causality between gene pairs inferred by Scribe}
\usage{
plot_temporal_causality(temp_causality_list, type = c("rdi", "crdi"),
  return_heatmap = FALSE, ...)
}
\arguments{
\item{temp_causality_list}{A list returned from the calculate_temporal_causality function}

\item{type}{A character describing which type of the data, either rdi or crdi, you would like to use for making the temporal causality plot}

\item{return_heatmap}{Whether or not to return the result for making the heatmap, default to be FALSE}

\item{...}{Additional argument passed into the pheatmap function}
}
\value{
a plot object
}
\description{
This function takes input from the result of calculate_temporal_causality function and plots the smoothed temporal RDI over pseudotime. The 
temporal RDI is ordered by the time point corresponds to the maximal temporal causality value.
}
\examples{
\dontrun{
lung <- load_lung() 
temp_causality_list <- calculate_temporal_causality(lung[1:5, ], delay = 5, log = TRUE)
plot_temporal_causality(temp_causality_list)
}
}
\references{
calculate_temporal_causality
}
