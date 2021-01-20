SELECT  movies.title
FROM movies
JOIN stars
	ON stars.movie_id = movies.id
JOIN people
	ON stars.person_id = people.id
		AND name = "Chadwick Boseman"
JOIN ratings
	ON movies.id = ratings.movie_id
ORDER BY ratings.rating DESC
LIMIT 5