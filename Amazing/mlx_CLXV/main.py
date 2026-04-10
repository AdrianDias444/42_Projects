import time

from mlx import Mlx

m = Mlx()
mlx_ptr = m.mlx_init()
window = m.mlx_new_window(mlx_ptr, 400, 300, "screen")


inicio = time.time()

m.mlx_loop(mlx_ptr)
m.mlx_destroy1_window(mlx_ptr)
