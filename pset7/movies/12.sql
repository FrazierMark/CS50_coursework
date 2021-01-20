SELECT  movies.title FROM movies
JOIN stars
	ON stars.movie_id = movies.id
JOIN people
	ON stars.person_id = people.id
		WHERE name =  "Johnny Depp"
INTERSECT
SELECT  movies.title FROM movies
JOIN stars
	ON stars.movie_id = movies.id
JOIN people
	ON stars.person_id = people.id
		WHERE name = "Helena Bonham Carter"