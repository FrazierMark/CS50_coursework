SELECT  round(avg(ratings.rating), 2) AS "Average Ratings, 2012"
FROM ratings
JOIN movies
ON ratings.movie_id = movies.id
AND movies.year = 2012
