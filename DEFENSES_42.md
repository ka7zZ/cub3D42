# Defensa 42 — cub3D (Preguntas robustas y respuestas)

Breve: aquí tienes tres defensas tipo corrección 42 (preguntas difíciles que pueden surgir durante la revisión del proyecto) con respuestas técnicas, concisas y justificadas al nivel de un alumno que ha superado Common Core y domina el motor.

## Checklist
- [x] Incluir 3 preguntas reales y técnicas que un corrector podría hacer.
- [x] Proveer respuestas completas, justas y defendibles (sin ambigüedad).
- [x] Mantener lenguaje técnico y referencias concretas a implementación (DDA, colisiones, MLX, Valgrind).

---

## Defensa 1 — Fish-eye y cálculo de distancia perpendicular

**Pregunta:**
Explica por qué ocurre el efecto "fish-eye" si uso la distancia euclidiana del rayo para proyectar paredes y cómo calculas la distancia perpendicular en tu implementación sin llamar a funciones trigonométricas costosas por cada rayo.

**Respuesta ideal:**
El fish-eye surge porque la distancia desde el jugador hasta la pared medida en dirección del rayo aumenta para rayos que van hacia los bordes del FOV; proyectar la pared usando esa distancia induce una distorsión angular. Para corregirlo hay que usar la distancia perpendicular al plano de la cámara. En lugar de calcular `dist * cos(angle)` por cada rayo, mi implementación usa las cantidades ya calculadas por el DDA: cuando el rayo impacta una celda, la distancia perpendicular se obtiene algebraicamente con fórmulas derivadas de la intersección con la rejilla:

- Si el impacto fue en X: perpDist = (mapX - posX + (1 - stepX) / 2) / rayDirX
- Si el impacto fue en Y: perpDist = (mapY - posY + (1 - stepY) / 2) / rayDirY

Estas expresiones evitan llamadas trigonométricas y usan solo sumas/divisiones. Además aprovechan que el DDA da `mapX/mapY` y `stepX/stepY`, por lo que es exacto y eficiente.

Edge-cases cubiertos:
- rayDirX o rayDirY cercanos a 0 revisados para evitar división por 0.
- ajuste de sub-pixel (hitbox) para evitar artefactos en bordes de celda.

---

## Defensa 2 — Movimiento diagonal y wall-sliding (anti-clipping)

**Pregunta:**
Cuando el jugador se mueve diagonalmente hacia una esquina (ej. W+A), muchos proyectos se "enganchan" o atraviesan paredes. Describe exactamente la lógica que empleas para evitar el stuttering y permitir wall-sliding sin permitir clipping.

**Respuesta ideal:**
El problema aparece si actualizas la posición con el vector total (dx, dy) y compruebas colisión una sola vez: si la posición resultante intersecta un muro, el jugador se bloquea. Mi solución es descomponer la intención de movimiento y aplicar colisión por componentes:

1. Calculo `newX = posX + dx * speed * delta_t` y pruebo si `newX` (con la hitbox) colisiona; si no, actualizo `posX`.
2. Independientemente, calculo `newY = posY + dy * speed * delta_t` y pruebo colisión; si no, actualizo `posY`.

Al proceder por ejes separados, si el jugador choca frontalmente con el muro en X, la componente Y sigue permitida y el jugador "resbala" a lo largo del muro. También:
- Uso un pequeño margen (EPS) / radio del jugador para evitar entrar en la celda de pared por errores de punto flotante.
- Verifico puertas dinámicas / celdas especiales antes de negar el movimiento.

Esto evita tanto el stuttering como el clipping por esquinas.

---

## Defensa 3 — Render buffer, MLX y Valgrind (still reachable)

**Pregunta:**
Valgrind muestra bloques "still reachable" (aprox. 30KB) al ejecutar tu binario. ¿Por qué aparecen y cómo justificas que no afectan la nota? Además, explica por qué no usas `mlx_pixel_put` y cómo implementas el render eficiente.

**Respuesta ideal:**
1) Origen de `still reachable`:
- Los bloques `still reachable` detectados provienen de la MinilibX / X11 y del estado interno del servidor gráfico (conexiones, colas y estructuras internas). No son "definitely lost" ni "indirectly lost". Yo libero explícitamente todos los recursos de mi programa: arrays, mapas, texturas y `mlx_destroy_image`/`mlx_destroy_window` cuando cierro. Por tanto, la fuga aparente es interna a MLX/Xlib y es tolerada en correcciones de 42 (documentado por muchos correctores debido a Xorg/MinilibX).

2) Render eficiente:
- Evité `mlx_pixel_put` porque hace llamadas por píxel a X11, lo que provoca un cuello de botella enorme.
- Uso `mlx_new_image` + `mlx_get_data_addr` para obtener un framebuffer en memoria y dibujo el frame entero en ese buffer (escritura en memoria: índice = y * line_length + x * (bpp/8)).
- Cuando el frame está listo hago un único `mlx_put_image_to_window`.
- Además, las texturas se memorizan y se muestrean con lookups en el buffer, no con llamadas al sistema.

3) Resultado en Valgrind:
- Mis pruebas con Valgrind muestran `0 bytes` en "definitely/indirectly/possibly lost". El `still reachable` corresponde a recursos MLX y no a mi código. Por tanto el manejo de memoria propio es correcto y defendible.

---

## Notas finales rápidas
- Si el corrector pide fragmentos concretos, referencia funciones: DDA (`ft_perform_dda` / `ft_raycast_frame`), movimiento (`ft_move_player` / `ft_update_player`) y limpieza (`ft_free_game`, `ft_free_textures`).
- Mantén ejemplos cortos en la exposición: un par de líneas con las fórmulas del DDA y el pseudocódigo para el movimiento por ejes.

---

Si quieres, pongo esto también en un `README_DEFENSES.md` más extenso con extractos de código (función corta de `ft_perform_dda` y pseudocódigo `ft_move_player`) y ejemplos de salida de Valgrind para que muestres durante la defensa.
