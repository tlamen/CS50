SELECT name
FROM people JOIN stars
ON people.id = stars.person_id
WHERE stars.movie_id IN (SELECT id FROM movies WHERE year = "2004")
GROUP BY people.id
ORDER BY people.birth;