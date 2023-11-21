import tensorflow as tf

model_dir = './'  # Path to the SavedModel directory
output_filepath = 'model.pbtxt'  # Path to save the .pbtxt file

# Load the SavedModel
loaded = tf.saved_model.load(model_dir)
concrete_func = loaded.signatures[tf.saved_model.DEFAULT_SERVING_SIGNATURE_DEF_KEY]

# Get the GraphDef
graph_def = concrete_func.graph.as_graph_def()

# Write the GraphDef to a .pbtxt file
with open(output_filepath, 'w') as f:
    f.write(str(graph_def))