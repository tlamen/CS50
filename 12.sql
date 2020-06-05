SELECT title
FROM movies JOIN stars
ON movies.id = stars.movie_id
WHERE stars.person_id IN (SELECT id FROM people WHERE name = "Johnny Depp")
OR stars.person_id IN (SELECT id FROM people WHERE name = "Helena Bonham Carter")
GROUP BY movies.id
ORDER BY COUNT(title) DESC
LIMIT 6;