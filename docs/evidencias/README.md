# Evidencias de pruebas y validaciones

Esta carpeta almacenará los registros utilizados para respaldar la sección **Pruebas y Validaciones** de `INFORME.md`.

En esta versión todavía no se incluyen resultados experimentales. Añadir un archivo aquí no implica que una prueba esté aprobada: su evaluación debe registrarse también en el informe.

## Evidencias previstas

| Tipo de prueba | Evidencia recomendada |
|---|---|
| Funcionamiento y rangos | Fotografías o video del montaje, el objeto de referencia y los LEDs |
| Exactitud | Registro Serial y fotografías de la cinta métrica para cada distancia |
| Estabilidad | Registro Serial continuo de al menos 10 minutos y observaciones de la sesión |
| Tiempo de respuesta | Video o registro temporal que permita identificar el cambio de rango y la respuesta |
| Frecuencia de muestreo | Captura completa de Serial con marcas de tiempo |

## Convención de nombres

Usar nombres descriptivos, sin espacios y con fecha en formato `AAAA-MM-DD`. Por ejemplo:

```text
exactitud_10cm_2026-09-13.txt
estabilidad_10min_2026-09-13.txt
respuesta_rojo_amarillo_2026-09-13.mp4
muestreo_2026-09-13.txt
montaje_general_2026-09-13.jpg
```

Cada evidencia debe indicar, dentro del archivo o en el informe:

- fecha y responsables;
- versión o commit del firmware;
- condiciones de la prueba;
- instrumento de referencia utilizado;
- caso de prueba relacionado;
- observaciones relevantes.

Se deben conservar los datos originales. Los cálculos derivados pueden añadirse como archivos separados, sin reemplazar el registro fuente.
